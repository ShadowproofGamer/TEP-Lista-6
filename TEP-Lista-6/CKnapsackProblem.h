#pragma once
#include "constants.h"

using namespace std;

class CKnapsackProblem
{
private:
	double backpackSize = 0;
	vector<pair<double, double>> itemTable;
	int constructionError = 0;
	int answerError = 0;
public:
	CKnapsackProblem();
	CKnapsackProblem(double size);
	CKnapsackProblem(vector<pair<double, double>> table);
	CKnapsackProblem(double size, vector<pair<double, double>> table);
	CKnapsackProblem(string filePath);
	CKnapsackProblem(int items);
	CKnapsackProblem(int items, double size);
	//optional constructors
	//CGeneticAlgorithm(vector<int> values, vector<int> sizes);
	//CGeneticAlgorithm(int size, vector<int> values, vector<int> sizes );
	//CGeneticAlgorithm(int size, vector<tuple<int, int>> table);
	double getAnswerValue(vector<int>* answer);
	double getAnswerValue(vector<bool>* answer);
	double getBackpackSize();
	int getItemsAmount();
};

