#include "CGeneticAlgorithm.h"

CGeneticAlgorithm::CGeneticAlgorithm()
{
	population = DEFPOPULATION;
	crossProbability = DEFCROSSPROBABILITY;
	mutateProbability = DEFMUTATEPROBABILITY;
	algo = new CKnapsackProblem();
	individuals = new vector<CIndividual*>;
	bestFitness = -1;
};
CGeneticAlgorithm::CGeneticAlgorithm(int pop, double cross, double mutate)
{
	if ((population = pop)<=0) population = DEFPOPULATION;
	if ((crossProbability = cross)<=0) crossProbability = DEFCROSSPROBABILITY;
	if ((mutateProbability = mutate)) mutateProbability = DEFMUTATEPROBABILITY;
	algo = new CKnapsackProblem();
	individuals = new vector<CIndividual*>;
	bestFitness = -1;
};
CGeneticAlgorithm::CGeneticAlgorithm(CKnapsackProblem* algorithm)
{
	population = DEFPOPULATION;
	crossProbability = DEFCROSSPROBABILITY;
	mutateProbability = DEFMUTATEPROBABILITY;
	algo = algorithm;
	individuals = new vector<CIndividual*>;
	bestFitness = -1;
};
CGeneticAlgorithm::CGeneticAlgorithm(int pop, double cross, double mutate, CKnapsackProblem* algorithm)
{
	if ((population = pop) <= 0) population = DEFPOPULATION;
	if ((crossProbability = cross) <= 0) crossProbability = DEFCROSSPROBABILITY;
	if ((mutateProbability = mutate)) mutateProbability = DEFMUTATEPROBABILITY;
	algo = algorithm;
	individuals = new vector<CIndividual*>;
	bestFitness = -1;
};
void CGeneticAlgorithm::initializePopulation() {
	//adding vector 0
	vector<int>* tmp = new vector<int>;
	for (size_t i = 0; i < algo->getItemsAmount(); i++)
	{
		tmp->push_back(0);
	}
	individuals->push_back(new CIndividual(tmp));
	//adding vectors (random):
	for (size_t i = 0; i < (population-1); i++)
	{
		individuals->push_back(new CIndividual(algo->getItemsAmount()));
	}
}

void CGeneticAlgorithm::settleBestFitness()
{
	for (size_t i = 0; i < individuals->size(); i++)
	{
		
		if (individuals->at(i)->getFitness() == -1) individuals->at(i)->calculateFitness(algo);
		if (individuals->at(i)->getFitness() > bestFitness)
		{
			bestFitness = individuals->at(i)->getFitness();
			cout << "found new best fitness: " << bestFitness << "\n";
		
		}
	}
}

double CGeneticAlgorithm::getBestFitness() 
{
	settleBestFitness();
	return bestFitness;
}

void CGeneticAlgorithm::runOptimization()
{

	cout << "results:" << endl;
	initializePopulation();
	settleBestFitness();



	time_t startTime = time(0);
	time_t currentTime = time(0);
	while (currentTime - startTime < DEFTIME)
	{

		
		srand(time(0));
		for (size_t i = 0; i < population; i++)
		{
			if (rand()%1000 > crossProbability*1000)
			{
				CIndividual* tempIndividual = (individuals->at(rand() % individuals->size())->reproduce(individuals->at(rand() % individuals->size())));
				individuals->push_back(tempIndividual);
			}
		}
		for (size_t i = 0; i < population; i++)
		{
			if(rand()%1000 > mutateProbability*1000)
			{
				
				CIndividual* tempIndividual =  individuals->at(rand() % individuals->size());
				
				tempIndividual->mutate(DEFMUTATEPERCENT);
				
			}
		}
		
		settleBestFitness();
		cleanPopulation();
		currentTime = time(0);
	}
	cout << "\nbest fitness achieved: " << getBestFitness() << endl;
	cout << "\nbest genetic code achieved: " << individuals->front()->getVector() <<"\n\n\n" << endl;

};

void CGeneticAlgorithm::cleanPopulation()
{
	sortVector();

	int tmp = (individuals->size());
	
	size_t i = population;
	for (i; i < tmp; i++)
	{
		delete individuals->back();
		individuals->pop_back();
	}
	
};

bool compareCIndividual(CIndividual* i1, CIndividual* i2)
{
	return (i1->getFitness() > i2->getFitness());
};

void CGeneticAlgorithm::sortVector()
{
	sort(individuals->begin(), individuals->end(), compareCIndividual);
};

void CGeneticAlgorithm::showAnswers() 
{
	for (size_t i = 0; i < individuals->size(); i++)
	{
		cout << individuals->at(i)->getVector() << endl;
	};
}
