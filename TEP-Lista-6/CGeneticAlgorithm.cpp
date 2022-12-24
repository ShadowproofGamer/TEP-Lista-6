#include "CGeneticAlgorithm.h"


CGeneticAlgorithm::CGeneticAlgorithm() {
	backpackSize = DEFBACKPACKSIZE;
	for (int i = 0; i < DEFITEMCOUNT; i++)
	{
		itemTable[i] = make_pair(i, i);
	}
	constructionError = 0;
};
CGeneticAlgorithm::CGeneticAlgorithm(double size) {
	if (size > 0) backpackSize = size;
	else
	{
		backpackSize = DEFBACKPACKSIZE;
		constructionError = ERRORSIZE;
	}
	for (int i = 0; i < DEFITEMCOUNT; i++)
	{
		itemTable[i] = make_pair(i, i);
	}

};
CGeneticAlgorithm::CGeneticAlgorithm(vector<pair<double, double>> table) {
	if (table.size() > 0) itemTable = table;
	else
	{
		for (int i = 0; i < DEFITEMCOUNT; i++)
		{
			itemTable[i] = make_pair(i, i);
		}
		constructionError = ERRORVECTOR;
	}
	backpackSize = DEFBACKPACKSIZE;
};
CGeneticAlgorithm::CGeneticAlgorithm(double size, vector<pair<double, double>> table) {
	if (size > 0) backpackSize = size;
	else
	{
		backpackSize = DEFBACKPACKSIZE;
		constructionError = ERRORSIZE;
	}

	if (table.size() > 0) itemTable = table;
	else 
	{
		for (int i = 0; i < DEFITEMCOUNT; i++)
		{
			itemTable[i] = make_pair(i, i);
		}
		if (constructionError == ERRORSIZE)constructionError = ERRORBOTH;
		else constructionError = ERRORVECTOR;
	}
};
