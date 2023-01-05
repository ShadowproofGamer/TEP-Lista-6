#include "CGeneticAlgorithm.h"

CGeneticAlgorithm::CGeneticAlgorithm()
{
	population = DEFPOPULATION;
	crossProbability = DEFCROSSPROBABILITY;
	mutateProbability = DEFMUTATEPROBABILITY;
	algo = new CKnapsackProblem();
	individuals = new vector<CIndividual*>;
};
CGeneticAlgorithm::CGeneticAlgorithm(int pop, double cross, double mutate)
{
	if ((population = pop)<=0) population = DEFPOPULATION;
	if ((crossProbability = cross)<=0) crossProbability = DEFCROSSPROBABILITY;
	if ((mutateProbability = mutate)) mutateProbability = DEFMUTATEPROBABILITY;
	algo = new CKnapsackProblem();
	individuals = new vector<CIndividual*>;
};
CGeneticAlgorithm::CGeneticAlgorithm(CKnapsackProblem* algorithm)
{
	population = DEFPOPULATION;
	crossProbability = DEFCROSSPROBABILITY;
	mutateProbability = DEFMUTATEPROBABILITY;
	algo = algorithm;
	individuals = new vector<CIndividual*>;
};
CGeneticAlgorithm::CGeneticAlgorithm(int pop, double cross, double mutate, CKnapsackProblem* algorithm)
{
	if ((population = pop) <= 0) population = DEFPOPULATION;
	if ((crossProbability = cross) <= 0) crossProbability = DEFCROSSPROBABILITY;
	if ((mutateProbability = mutate)) mutateProbability = DEFMUTATEPROBABILITY;
	algo = algorithm;
	individuals = new vector<CIndividual*>;
};
void CGeneticAlgorithm::initializePopulation() {
	for (size_t i = 0; i < population; i++)
	{
		individuals->push_back(new CIndividual(algo->getBackpackSize()));
	}
}

void CGeneticAlgorithm::settleBestFitness()
{
	for (size_t i = 0; i < individuals->size(); i++)
	{
		//CIndividual* temp = individuals.at(i);
		if (individuals->at(i)->getFitness() == -1) individuals->at(i)->calculateFitness(algo);
		if (individuals->at(i)->getFitness() > bestFitness)
		{
			bestFitness = individuals->at(i)->getFitness();
			cout << bestFitness << "\n";
		
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

		
		cout << "tempSizeV: " << individuals->size() << "\n";
		srand(time(0));
		for (size_t i = 0; i < population; i++)
		{
			if (rand()%1000 > crossProbability*1000)
			{
				CIndividual* tempIndividual = individuals->at(rand() % individuals->size())->reproduce(individuals->at(rand() % individuals->size()));
				individuals->push_back(tempIndividual);
			}
		}
		cout << "tempSizeV after for 1: " << individuals->size() << "\n";
		for (size_t i = 0; i < population; i++)
		{
			if(rand()%1000 > mutateProbability*1000)
			{
				//TODO effective individual copying
				CIndividual* tempIndividual =  individuals->at(rand() % individuals->size());
				//!
				tempIndividual->mutate(DEFMUTATEPERCENT);
				individuals->push_back(tempIndividual);
			}
		}
		cout << "tempSizeV after for 2: " << individuals->size() << "\n";
		settleBestFitness();
		cleanPopulation();
		//currentTime = time(0);
		cout << "best fitness: " << getBestFitness() << " time: " << (startTime-currentTime) << endl;
	}
	cout << getBestFitness() << endl;

};

void CGeneticAlgorithm::cleanPopulation()
{
	sortVector();
	cout << "Size before cleaning: " << individuals->size() << " population before cleaning: " << population << "\n";

	
	for (size_t i = population; i < (individuals->size()); i++)
	{
		individuals->erase(individuals->begin()+population);
	}

	cout << "Size after cleaning: " << individuals->size() << " population before cleaning: " << population << "\n";
};

bool compareCIndividual(CIndividual* i1, CIndividual* i2)
{
	return (i1->getFitness() > i2->getFitness());
};

void CGeneticAlgorithm::sortVector()
{
	sort(individuals->begin(), individuals->end(), compareCIndividual);
};


