#include "CIndividual.h"

CIndividual::CIndividual()
{
	answer = new vector<int>;
	srand(time(0));
	for (size_t i = 0; i < DEFBACKPACKSIZE; i++)
	{
		answer->push_back(rand() % 2);
	}
};

CIndividual::CIndividual(int length)
{
	answer = new vector<int>;
	srand(time(0));
	for (size_t i = 0; i < length; i++)
	{
		answer->push_back(rand()%2);
	}
};

CIndividual::CIndividual(vector<int>* other)
{
	answer = new vector<int>;
	for (size_t i = 0; i < other->size(); i++)
	{
		answer->push_back(other->at(i));
	}
};

void CIndividual::calculateFitness(CKnapsackProblem* parent)
{
	fitness = (parent->getAnswerValue(answer));
};

void CIndividual::mutate()
{
	int size = answer->size();
	int iter = roundl(DEFMUTATEPROBABILITY * size);
	int i = 0;
	while (iter > 0)
	{
		srand(time(0));
		if (rand() % 2 == 0) {
			(answer->at(i) += 1) %= 2;
			iter--;
		}
		(++i) %= size;
	}
};

void CIndividual::mutate(double percentToMutate)
{
	int size = answer->size();
	int iter = roundl(percentToMutate*size);
	int i = 0;
	while (iter>0)
	{
		srand(time(0));
		if (rand() % 2 == 0) {
			(answer->at(i) += 1) %= 2;
			iter--;
		} 
		(++i) %= size;
	}
};

CIndividual* CIndividual::reproduce(CIndividual* partner)
{
	if (partner != this)
	{
		srand(time(0));
		int size = answer->size();
		double cut = rand() % size;
		vector<int>* newAnswer = new vector<int>;
		for (size_t i = 0; i < cut; i++)
		{
			newAnswer->push_back(answer->at(i));
		}
		for (size_t i = cut; i < size; i++)
		{
			newAnswer->push_back(partner->answer->at(i));
		}
		return new CIndividual(newAnswer);
	}
	else return this;
};

double CIndividual::getFitness() {
	return fitness;
}

CIndividual::~CIndividual()
{
	answer->clear();
	answer = NULL;
};

CIndividual* CIndividual::mutateInd()
{
	CIndividual* tempIndividual = new CIndividual(answer);
	int size = answer->size();
	int iter = roundl(DEFMUTATEPROBABILITY * size);
	int i = 0;
	while (iter > 0)
	{
		srand(time(0));
		if (rand() % 2 == 0) {
			(tempIndividual->answer->at(i) += 1) %= 2;
			iter--;
		}
		(++i) %= size;
	}
	return tempIndividual;
};

CIndividual* CIndividual::mutateInd(double percentToMutate)
{
	CIndividual* tempIndividual = new CIndividual(answer);
	int size = answer->size();
	int iter = roundl(percentToMutate * size);
	int i = 0;
	while (iter > 0)
	{
		srand(time(0));
		if (rand() % 2 == 0) {
			(tempIndividual->answer->at(i) += 1) %= 2;
			iter--;
		}
		(++i) %= size;
	}
	return tempIndividual;
};

string CIndividual::getVector()
{
	string str = "";
	for (size_t i = 0; i < answer->size(); i++)
	{
		str.push_back(answer->at(i)+48);
	}
	return str;
};

