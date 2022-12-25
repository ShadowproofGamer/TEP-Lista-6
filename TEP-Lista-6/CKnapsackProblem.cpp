#include "CKnapsackProblem.h"


CKnapsackProblem::CKnapsackProblem() {
	backpackSize = DEFBACKPACKSIZE;
	for (int i = 0; i < DEFITEMCOUNT; i++)
	{
		itemTable.push_back(make_pair(i, i));
	}
	constructionError = 0;
};

CKnapsackProblem::CKnapsackProblem(double size) {
	if (size > 0) backpackSize = size;
	else
	{
		backpackSize = DEFBACKPACKSIZE;
		constructionError = ERRORSIZE;
	}
	for (int i = 0; i < DEFITEMCOUNT; i++)
	{
		itemTable.push_back(make_pair(i, i));
	}

};

CKnapsackProblem::CKnapsackProblem(vector<pair<double, double>> table) {
	if (table.size() > 0) itemTable = table;
	else
	{
		for (int i = 0; i < DEFITEMCOUNT; i++)
		{
			itemTable.push_back(make_pair(i, i));
		}
		constructionError = ERRORVECTOR;
	}
	backpackSize = DEFBACKPACKSIZE;
};

CKnapsackProblem::CKnapsackProblem(double size, vector<pair<double, double>> table) {
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
			itemTable.push_back(make_pair(i, i));
		}
		if (constructionError == ERRORSIZE)constructionError = ERRORBOTH;
		else constructionError = ERRORVECTOR;
	}
};

double CKnapsackProblem::getAnswerValue(vector<int> answer)
{
	double result = 0;
	double size = 0;
	for (int i = 0; i < answer.size(); i++)
	{
		if (answer.at(i) == 1)
		{
			result += itemTable.at(i).first;
			size += itemTable.at(i).second;
		}
		
	}
	if (size > backpackSize) return result;
	else return -1;
}