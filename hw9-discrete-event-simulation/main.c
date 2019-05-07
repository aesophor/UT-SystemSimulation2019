#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "list.h"

static float arr_lambda;
static float dep_labmda;
static float simulation_time;

static float master_clock;
static Node* fel_head = NULL;
static Node* customer_q = NULL;

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

}

static void
onDeparture() {

}


int
main(int argc, char* args[]) {
  if (argc < 4) {
    printf("usage: %s <arr_lambda> <dep_lambda> <simulation_time>\n", args[0]);
    return EXIT_SUCCESS;
  }

  srand(time(NULL));
  arr_lambda = atof(args[1]);
  dep_labmda = atof(args[2]);
  simulation_time = atof(args[3]);

  master_clock = .0f;

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
  }
  return EXIT_SUCCESS;
}
