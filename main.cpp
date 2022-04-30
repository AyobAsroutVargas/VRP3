#include "file-loader.h"
#include "greedy-vrp.h"
#include "grasp-vrp.h"
#include "solution.h"


int main(int argc, char* argv[]) {
  std::string filename = "I40j_2m_S1_1.txt";
  if (argc == 2) {
    filename = argv[1];
  }
  int nClients = 0, nVehicles = 0;
  std::vector<std::vector<int>> distanceMatrix;
  loadFromFile("I40j_2m_S1_1.txt", distanceMatrix, nClients, nVehicles);
  Problem problem(distanceMatrix, nClients, nVehicles);
  GreedyVrp greedy(problem);
  Solution greedySolution(greedy.Solve(), distanceMatrix);

  EnviromentStructure* reinsertionIntra = new ReinsertionIntra();
  EnviromentStructure* reinsertionEntre = new ReinsertionEntre();
  EnviromentStructure* swapIntra = new SwapIntra();
  EnviromentStructure* swapEntre = new SwapEntre();

  GraspVrp graspRIntra(problem, reinsertionIntra);
  GraspVrp graspREntre(problem, reinsertionEntre);
  GraspVrp graspSIntra(problem, swapIntra);
  GraspVrp graspSEntre(problem, swapEntre);

  Solution graspRIntraSolution(graspRIntra.generateInitialSolution(), distanceMatrix);
  Solution graspREntreSolution(graspREntre.generateInitialSolution(), distanceMatrix);
  Solution graspSIntraSolution(graspSIntra.generateInitialSolution(), distanceMatrix);
  Solution graspSEntreSolution(graspSEntre.generateInitialSolution(), distanceMatrix);
  std::cout << "Greedy\n";
  greedySolution.print();
  std::cout << "\n\n\n";
  std::cout << "Grasp(reinsercion-Intra)\n";
  graspRIntraSolution.print();
  std::cout << "\n\n\n";
  std::cout << "Grasp(reinsercion-Entre)\n";
  graspREntreSolution.print();
  std::cout << "\n\n\n";
  std::cout << "Grasp(intercambio-Intra)\n";
  graspSIntraSolution.print();
  std::cout << "\n\n\n";
  std::cout << "Grasp(intercambio-Entre)\n";
  graspSEntreSolution.print();
  std::cout << "\n\n\n";
}