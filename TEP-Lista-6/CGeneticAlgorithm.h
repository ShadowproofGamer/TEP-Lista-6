#pragma once
#include "constants.h"
#include "CIndividual.h"
#include <algorithm>

using namespace std;
class CGeneticAlgorithm
{
private:
	int population;
	double crossProbability;
	double mutateProbability;
	double bestFitness;
	vector<CIndividual*> individuals;
	CKnapsackProblem* algo;
public:
	CGeneticAlgorithm();
	CGeneticAlgorithm(int pop, double cross, double mutate);
	void initializePopulation();
	void runOptimization();
	void settleBestFitness();
	double getBestFitness();
	void cleanPopulation();
	void sortVector();
};

