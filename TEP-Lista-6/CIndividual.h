#pragma once
#include "constants.h"
#include <cstdlib>
#include <time.h>
#include "CKnapsackProblem.h"

using namespace std;

class CIndividual
{
private:
	vector<int>* answer;
	CKnapsackProblem* parent;
	double fitness = 0;
public:
	CIndividual();
	CIndividual(int vectorLength);
	CIndividual(vector<int>* other);
	void calculateFitness();
	void mutate();
	void mutate(double percentToMutate);
	CIndividual* reproduce(CIndividual* partner);
};

