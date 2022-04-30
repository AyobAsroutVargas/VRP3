#ifndef REINSERTION_ENTRE
#define REINSERTION_ENTRE

#include "estructura-entorno.h"

class ReinsertionEntre : public EnviromentStructure {
 public:
  std::vector<std::vector<int>> Apply(Solution initialSolution);
};

#endif