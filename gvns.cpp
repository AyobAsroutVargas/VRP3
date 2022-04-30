#include "gvns.h"

Gvns::Gvns(Problem problem, int maxClients) {
  problem_ = problem;
  maxClients_ = maxClients;
}