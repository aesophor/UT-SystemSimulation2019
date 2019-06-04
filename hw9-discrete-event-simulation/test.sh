#!/usr/bin/env bash

time=1000000
output="output.txt"

./main 0.1 0.85 $time > $output
./main 0.15 0.85 $time >> $output
./main 0.2 0.85 $time >> $output
./main 0.25 0.85 $time >> $output
./main 0.3 0.85 $time >> $output
./main 0.35 0.85 $time >> $output
./main 0.4 0.85 $time >> $output
./main 0.45 0.85 $time >> $output
./main 0.5 0.85 $time >> $output
./main 0.55 0.85 $time >> $output
./main 0.6 0.85 $time >> $output
./main 0.65 0.85 $time >> $output
./main 0.7 0.85 $time >> $output
./main 0.75 0.85 $time >> $output
./main 0.8 0.85 $time >> $output
