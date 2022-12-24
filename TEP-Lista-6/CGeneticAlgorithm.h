#pragma once
#include "constants.h"

using namespace std;
class CGeneticAlgorithm
{
private:
	double backpackSize;
	vector<pair<double, double>> itemTable;
	int constructionError = 0;
public:
	CGeneticAlgorithm();
	CGeneticAlgorithm(double size);
	CGeneticAlgorithm(vector<pair<double, double>> table);
	CGeneticAlgorithm(double size, vector<pair<double, double>> table);
	//optional constructors
	//CGeneticAlgorithm(vector<int> values, vector<int> sizes);
	//CGeneticAlgorithm(int size, vector<int> values, vector<int> sizes );
	//CGeneticAlgorithm(int size, vector<tuple<int, int>> table);


};

