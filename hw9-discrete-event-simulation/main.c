#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "list.h"

static float arr_lambda;
static float dep_lambda;
static float simulation_time;

static float master_clock;
static Node* fel_head = NULL;
static Node* customer_q_head = NULL;
static int is_busy = 0;

static float waiting_time_sum = 0;
static int num_people = 0;


static double doubleRand(double min, double max);
static double expRand(double lambda);

static void onArrival();
static void onDeparture();


// Pseudo random number generator
static double
doubleRand(double min, double max) {
  double div = RAND_MAX / (max - min);
  return min + (rand() / div);
}

// Exponential distribution sampling
static double
expRand(double lambda) {
  return ((double) -1) / lambda * log(1 - doubleRand(0, 1));
}


// Event handlers
static void
onArrival() {
  // Schedule the next arrival event.
  insertNode(fel_head, &fel_head, newNode(ARRIVAL, master_clock + expRand(arr_lambda)));

  if (is_busy) { // server is busy
    insertHead(customer_q_head, &customer_q_head, newNode(0, master_clock));
  } else { // server is empty
    num_people++;
    is_busy = 1;
    // Schedule a departure event for this customer
    insertNode(fel_head, &fel_head, newNode(DEPARTURE, master_clock + expRand(dep_lambda)));
  }
}

static void
onDeparture() {
  if (!customer_q_head) { // customer q is empty
    is_busy = 0;
  } else { // not empty
    Node* tail = removeTail(customer_q_head, &customer_q_head);
    float delay = master_clock - tail->clock;
    waiting_time_sum += delay;
    num_people++;
    free(tail);
    // Schedule next departure event for the next customer.
    insertNode(fel_head, &fel_head, newNode(DEPARTURE, master_clock + expRand(dep_lambda)));
  }
}

static double
getTheoryWaitingTime() {
  double l = arr_lambda / (dep_lambda - arr_lambda);
  double w = l / (arr_lambda);
  return w - 1 / dep_lambda;
}


int
main(int argc, char* args[]) {
  if (argc < 4) {
    printf("usage: %s <arr_lambda> <dep_lambda> <simulation_time>\n", args[0]);
    return EXIT_SUCCESS;
  }

  srand(time(NULL));
  arr_lambda = atof(args[1]);
  dep_lambda = atof(args[2]);
  simulation_time = atof(args[3]);

  master_clock = .0f;
  insertNode(fel_head, &fel_head, newNode(ARRIVAL, master_clock + expRand(arr_lambda)));

  while (master_clock < simulation_time) {
    Node* current_event = removeHead(fel_head, &fel_head);
    master_clock = current_event->clock;

    switch (current_event->type) {
      case ARRIVAL:
        onArrival();
        break;
      case DEPARTURE:
        onDeparture();
        break;
      default:
        printf("ERROR: No such event type!\n");
        break;
    }
    free(current_event);
  }

  // Report
  //printf("total waiting time: %f\n", waiting_time_sum);
  //printf("total number of people: %d\n", num_people);
  printf("arr=%f\tdep=%f\t", arr_lambda, dep_lambda);
  printf("平均等待時間: %f\t", waiting_time_sum / num_people);
  printf("理論等待時間: %f\n", getTheoryWaitingTime());
  return EXIT_SUCCESS;
}
