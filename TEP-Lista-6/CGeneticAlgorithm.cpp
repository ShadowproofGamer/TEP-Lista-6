#include "CGeneticAlgorithm.h"

CGeneticAlgorithm::CGeneticAlgorithm()
{
	population = DEFPOPULATION;
	crossProbability = DEFCROSSPROBABILITY;
	mutateProbability = DEFMUTATEPROBABILITY;
};
CGeneticAlgorithm::CGeneticAlgorithm(int pop, double cross, double mutate)
{
	if ((population = pop)<=0) population = DEFPOPULATION;
	if ((crossProbability = cross)<=0) crossProbability = DEFCROSSPROBABILITY;
	if ((mutateProbability = mutate)) mutateProbability = DEFMUTATEPROBABILITY;
};
void CGeneticAlgorithm::initializePopulation() {
	for (size_t i = 0; i < population; i++)
	{
		individuals.push_back(new CIndividual(algo->getBackpackSize()));
	}
}

void CGeneticAlgorithm::settleBestFitness()
{
	for (size_t i = 0; i < individuals.size(); i++)
	{
		CIndividual* temp = individuals.at(i);
		if (temp->getFitness() == -1) temp->calculateFitness(algo);
		else if (temp->getFitness() > bestFitness) bestFitness = temp->getFitness();
	}
}

double CGeneticAlgorithm::getBestFitness() 
{
	settleBestFitness();
	return bestFitness;
}

void CGeneticAlgorithm::runOptimization()
{
	/*
	int population;
	double crossProbability;
	double mutateProbability;
	double bestFitness;
	vector<CIndividual*> individuals;
	CKnapsackProblem* algo;
	*/
	initializePopulation();
	settleBestFitness();
	time_t startTime = time(0);
	time_t currentTime = time(0);
	while (currentTime - startTime < DEFTIME)
	{
		int tempSizeV = individuals.size();
		srand(time(0));
		for (size_t i = 0; i < tempSizeV; i++)
		{
			if (rand()%1000 > crossProbability*1000)
			{
				CIndividual* tempIndividual = individuals.at(rand() % tempSizeV)->reproduce(individuals.at(rand() % tempSizeV));
				individuals.push_back(tempIndividual);
			}
		}
		for (size_t i = 0; i < tempSizeV; i++)
		{
			if(rand()%1000 > mutateProbability*1000)
			{
				//TODO effective individual copying
				CIndividual* tempIndividual =  individuals.at(rand() % tempSizeV);
				//!
				tempIndividual->mutate(DEFMUTATEPERCENT);
				individuals.push_back(tempIndividual);
			}
		}
		settleBestFitness();
		cleanPopulation();
	}


};

void CGeneticAlgorithm::cleanPopulation()
{
	sortVector();
	for (size_t i = population; i < individuals.size(); i++)
	{
		individuals.pop_back();
	}
};

bool compareCIndividual(CIndividual* i1, CIndividual* i2)
{
	return (i1->getFitness() > i2->getFitness());
};

void CGeneticAlgorithm::sortVector()
{
	sort(individuals.begin(), individuals.end(), compareCIndividual);
};


