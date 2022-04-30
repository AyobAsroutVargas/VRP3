#ifndef GVNS
#define GVNS

#include <vector>
#include <set>
#include <climits>
#include <cstdlib>
#include <ctime>
#include "vehicle.h"
#include "problem.h"
#include "solution.h"
#include <sys/time.h>
#include "reinsercion-intra.h"
#include "intercambio-intra.h"
#include "reinsercion-entre.h"
#include "intercambio-entre.h"

class Gvns {
 public:
  Gvns(Problem problem, int maxClients);
  Problem problem_;
  int maxClients_;
};

#endif