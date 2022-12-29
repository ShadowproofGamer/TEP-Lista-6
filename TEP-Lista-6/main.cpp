#include "CGeneticAlgorithm.h"
#include "CIndividual.h"
#include "CKnapsackProblem.h"

int main() {
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

	cout << prob.getAnswerValue(answers);












	return 0;
}