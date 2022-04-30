#ifndef ENVIROMENT_STRUCTURE
#define ENVIROMENT_STRUCTURE

#include <vector>
#include <set>
#include <climits>
#include <cstdlib>
#include <ctime>
#include "vehicle.h"
#include "problem.h"
#include "solution.h"

class EnviromentStructure {
 public:
  virtual std::vector<std::vector<int>> Apply(Solution initialSolution) = 0;
};

#endif