#include "Tests.h"

void Tests::test1()
{
	CKnapsackProblem prob("Tekst.txt");
	vector<int>* answers = new vector<int>;
	answers->push_back(0);
	answers->push_back(0);
	answers->push_back(1);
	answers->push_back(0);
	answers->push_back(0);
	answers->push_back(0);
	answers->push_back(1);
	answers->push_back(0);
	answers->push_back(0);
	answers->push_back(1);
	answers->push_back(1);

	cout << prob.getAnswerValue(answers) << "\n";
	answers->clear();
	cout << "cleared" << "\n";
	delete answers;
	cout << "deleted" << "\n";
};

void Tests::test2()
{
	vector<int>* answers = new vector<int>;
	answers->push_back(0);
	answers->push_back(0);
	answers->push_back(1);
	answers->push_back(0);
	answers->push_back(0);
	answers->push_back(0);
	answers->push_back(1);
	answers->push_back(0);
	answers->push_back(0);
	answers->push_back(1);
	answers->push_back(1);
	cout << "vector created" << "\n";

	CIndividual* i1 = new CIndividual();
	cout << "def constructor" << "\n";
	delete i1;
	cout << "def destructor" << "\n";

	CIndividual* i2 = new CIndividual(10);
	cout << "len constructor" << "\n";
	delete i2;
	cout << "len destructor" << "\n";

	//CIndividual* i3 = new CIndividual(i1);
	CIndividual* i4 = new CIndividual(answers);
	cout << "vector constructor" << "\n";
	delete i4;
	cout << "vector destructor" << "\n";

	answers->clear();
	cout << "cleared" << "\n";
	delete answers;
	cout << "deleted" << "\n";
};

void Tests::test3()
{
	CKnapsackProblem* algo = new CKnapsackProblem("Tekst.txt");
	CIndividual* i1 = new CIndividual(algo->getBackpackSize());
	cout << "def constructor" << "\n";
	i1->calculateFitness(algo);
	cout << "i1 fitness 1: " << i1->getFitness() <<"\n";
	cout << "i1 vector 1: " << i1->getVector() << "\n";
	i1->mutate();
	i1->calculateFitness(algo);
	cout << "i1 fitness 2: " << i1->getFitness() << "\n";
	cout << "i1 vector 2: " << i1->getVector() << "\n";
	CIndividual* i2 = i1->reproduce(i1);
	i2->calculateFitness(algo);
	cout << "i2 fitness 1: " << i2->getFitness() << "\n";
	cout << "i2 vector 1: " << i2->getVector() << "\n";
	
	delete i1;
	cout << "def destructor" << "\n";
};

void Tests::test4()
{
	CKnapsackProblem* algo = new CKnapsackProblem("Tekst1.txt"); //() ||"Tekst.txt" || "Tekst1.txt" - best 19
	CGeneticAlgorithm mainAlgo = CGeneticAlgorithm(1000, 0.7, 0.03, algo);
	mainAlgo.runOptimization();
};