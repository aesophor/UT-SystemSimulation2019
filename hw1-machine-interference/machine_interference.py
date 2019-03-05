#!/usr/bin/env python3
# -*- encoding: utf-8 -*-

# Copyright 2019 Marco Wang <m.aesophor@gmail.com>

from queue import Queue

class Machine:
    """ A machine has an id, lifetime and next_broken_time """
    def __init__(self, next_broken_time: int, lifetime: int):
        self.next_broken_time = next_broken_time
        self.lifetime = lifetime

    @property
    def is_broken(self):
        return self.next_broken_time == -1
        
    def set_broken(self, is_broken, master_clock):
        """ Set the machine's state
        :param is_broken: Either True or False
        :param master_clock: Indicates current time
        """
        if is_broken:
            self.next_broken_time = -1
        else:
            self.next_broken_time = master_clock + self.lifetime


class RepairMan:
    def __init__(self, repair_time=5):
        self.queue = Queue()
        self.next_fixed_time = -1
        self.repair_time = repair_time

    @property
    def is_busy(self):
        """ Check if the repair man is busy """
        return self.queue.qsize() > 0

    def repair(self, machine, master_clock):
        """ Ask the repair man to repair a machine
        :param machine: The machine that needs to be repaired
        :param master_clock: Indicates current time
        """
        if self.queue.empty():
            self.next_fixed_time = master_clock + self.repair_time
        self.queue.put(machine)

    def retrieve(self):
        """ Returns a repaired machine
        :returns: A repaired machine
        """
        repaired_machine = self.queue.get()
        self.next_fixed_time = self.next_fixed_time + self.repair_time if self.is_busy else -1
        return repaired_machine


class Simulator:
    def __init__(self):
        self.master_clock = 0
        self.machines = []
        self.repair_man = RepairMan()

    @property
    def machine_clocks(self):
        return [m.next_broken_time for m in self.machines]

    def add(self, *machines):
        self.machines += machines

    def next_event(self):
        """ Jumps to the next event """
        possible_event_time = [t for t in (self.machine_clocks + [self.repair_man.next_fixed_time]) if t != -1]
        self.master_clock = min(possible_event_time)

        # Check if any machine is broken
        for i, machine in enumerate(self.machines):
            if machine.next_broken_time != -1 and self.master_clock == machine.next_broken_time:
                self.machines[i].set_broken(True, self.master_clock)
                self.repair_man.repair(self.machines[i], self.master_clock)
                print(self.__str__())

        # Check if any machine's repairment is done
        if self.master_clock == self.repair_man.next_fixed_time:
            repaired_machine = self.repair_man.retrieve()
            repaired_machine.set_broken(False, self.master_clock)
            print(self.__str__())

    def __str__(self):
        master_clock = str(self.master_clock)
        machine_clocks = [str(m.next_broken_time) if m.next_broken_time != -1 else '-' for m in self.machines]
        repair_clock = str(self.repair_man.next_fixed_time) if self.repair_man.next_fixed_time != -1 else '-'
        repair_queue_size = str(self.repair_man.queue.qsize())
        repair_man_status = "busy" if self.repair_man.is_busy else "idle"
        return '\t'.join([master_clock] + machine_clocks + [repair_clock, repair_queue_size, repair_man_status])

    def run(self, rows: int):
        print('MC\tCL1\tCL2\tCL3\tCL4\tn\tR')
        print(self.__str__())

        for i in range(0, rows):
            self.next_event()



if __name__ == '__main__':
    simulator = Simulator()

    simulator.add(
        Machine(2, 10),
        Machine(3, 10),
        Machine(8, 10),
    )

    simulator.run(10)
