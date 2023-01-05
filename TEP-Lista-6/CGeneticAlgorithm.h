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
	double bestFitness = -1;
	vector<CIndividual*>* individuals;
	CKnapsackProblem* algo;
public:
	CGeneticAlgorithm();
	CGeneticAlgorithm(CKnapsackProblem* algorithm);
	CGeneticAlgorithm(int pop, double cross, double mutate);
	CGeneticAlgorithm(int pop, double cross, double mutate, CKnapsackProblem* algorithm);
	void initializePopulation();
	void runOptimization();
	void settleBestFitness();
	double getBestFitness();
	void cleanPopulation();
	void sortVector();
	void showAnswers();
};

