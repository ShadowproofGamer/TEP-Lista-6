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

	cout << prob.getAnswerValue(answers);
};