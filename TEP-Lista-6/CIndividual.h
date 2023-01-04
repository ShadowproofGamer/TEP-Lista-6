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
	double fitness = -1;
public:
	CIndividual();
	CIndividual(int vectorLength);
	CIndividual(vector<int>* other);
	~CIndividual();
	void calculateFitness(CKnapsackProblem* parent);
	void mutate();
	void mutate(double percentToMutate);
	CIndividual* mutateInd();
	CIndividual* mutateInd(double percentToMutate);
	CIndividual* reproduce(CIndividual* partner);
	double getFitness();
	string getVector();
};

