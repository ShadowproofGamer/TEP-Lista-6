#pragma once
#include "constants.h"

using namespace std;

class CKnapsackProblem
{
private:
	double backpackSize;
	vector<pair<double, double>> itemTable;
	int constructionError = 0;
public:
	CKnapsackProblem();
	CKnapsackProblem(double size);
	CKnapsackProblem(vector<pair<double, double>> table);
	CKnapsackProblem(double size, vector<pair<double, double>> table);
	//optional constructors
	//CGeneticAlgorithm(vector<int> values, vector<int> sizes);
	//CGeneticAlgorithm(int size, vector<int> values, vector<int> sizes );
	//CGeneticAlgorithm(int size, vector<tuple<int, int>> table);
	double getAnswerValue(vector<int> answer);
	double getAnswerValue(vector<bool> answer);
};

