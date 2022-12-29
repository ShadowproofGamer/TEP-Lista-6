#include "CKnapsackProblem.h"
using namespace std;

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

CKnapsackProblem::CKnapsackProblem(string filePath)
{
	try
	{
		ifstream myFile;
		myFile.open(filePath);
		if (myFile.is_open())
		{
			double backpackS, first, second;
			int lines = 0;
			myFile >> backpackS;
			backpackSize = backpackS;
			myFile >> lines;
			if (lines <= 0) throw new exception();
			for (size_t i = 0; i < lines; i++)
			{
				myFile >> first;
				myFile >> second;
				itemTable.push_back({ first, second });
				cout << first << "\t" << second << "\n";

			}
			myFile.close();
		}
		else
		{
			cout << "failed to load from file!\n";
			constructionError = FILENOTOPEN;
			CKnapsackProblem();
		}
		
	}
	catch (exception e) 
	{
		cout << "failed to load from file!\n";
		constructionError = FILECORRUPTED;
		CKnapsackProblem();
	}
};


double CKnapsackProblem::getAnswerValue(vector<int>* answer)
{
	double result = 0;
	double size = 0;
	int iter = 0;
	//it answer is longer than backpack than the too long records are ignored:
	if ((iter = answer->size()) > itemTable.size())
	{
		iter = itemTable.size();
		answerError = ANSWERTOOLONG;
	}
	for (int i = 0; i < iter; i++)
	{
		if (answer->at(i) == 1)
		{
			result += itemTable.at(i).first;
			size += itemTable.at(i).second;
		}
		
	}
	if (size <= backpackSize) return result;
	else return -1;
}

double CKnapsackProblem::getAnswerValue(vector<bool>* answer)
{
	double result = 0;
	double size = 0;
	int iter = 0;
	//it answer is longer than backpack than the too long records are ignored:
	if ((iter = answer->size()) > itemTable.size())
	{
		iter = itemTable.size();
		answerError = ANSWERTOOLONG;
	}
	for (int i = 0; i < iter; i++)
	{
		if (answer->at(i))
		{
			result += itemTable.at(i).first;
			size += itemTable.at(i).second;
		}
	}
	if (size <= backpackSize) return result;
	else return -1;
}