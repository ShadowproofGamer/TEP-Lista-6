#include "CKnapsackProblem.h"
using namespace std;

CKnapsackProblem::CKnapsackProblem() {
	srand(time(0));
	backpackSize = DEFBACKPACKSIZE;
	for (int i = 0; i < DEFITEMCOUNT; i++)
	{
		itemTable.push_back(make_pair(rand() % (i+1), rand() % (i+1)));
	}
	constructionError = 0;
	cout << "loading random problem:\n" << endl;
	printKnapsack();
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
				

			}
			myFile.close();
			cout << "succeeded to load from file '" << filePath << "'!\nproblem details:\n" << endl;
			printKnapsack();
		}
		else
		{
			
			constructionError = FILENOTOPEN;
			srand(time(0));
			backpackSize = DEFBACKPACKSIZE;
			for (int i = 0; i < DEFITEMCOUNT; i++)
			{
				itemTable.push_back(make_pair(rand() % (i + 1), rand() % (i + 1)));
			}
			constructionError = 0;
			cout << "failed to load from file '" << filePath << "'!\nloading random problem:\n" << endl;
			printKnapsack();
		}
		
	}
	catch (exception e) 
	{
		
		constructionError = FILECORRUPTED;
		srand(time(0));
		backpackSize = DEFBACKPACKSIZE;
		for (int i = 0; i < DEFITEMCOUNT; i++)
		{
			itemTable.push_back(make_pair(rand() % (i + 1), rand() % (i + 1)));
		}
		constructionError = 0;
		cout << "failed to load from file!\nloading random problem:\n" << endl;
		printKnapsack();
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



double CKnapsackProblem::getBackpackSize()
{
	return backpackSize;
};

int CKnapsackProblem::getItemsAmount()
{
	return itemTable.size();
};

void CKnapsackProblem::printKnapsack()
{
	cout << "backpack size: " << backpackSize << "\namount of items: " << itemTable.size() << "\n"; 
	cout << "worth:" << "\t\t" << "weight:" << endl;
	for (size_t i = 0; i < itemTable.size(); i++)
	{
		cout << itemTable.at(i).first << "\t\t" << itemTable.at(i).second << endl;
	}
	cout << endl;
}

/*
CKnapsackProblem::CKnapsackProblem(double size) {
	srand(time(0));
	if (size > 0) backpackSize = size;
	else
	{
		backpackSize = DEFBACKPACKSIZE;
		constructionError = ERRORSIZE;
	}
	for (int i = 0; i < DEFITEMCOUNT; i++)
	{
		itemTable.push_back(make_pair(rand() % (i+1), rand() % (i+1)));
	}

};

CKnapsackProblem::CKnapsackProblem(int items) {
	srand(time(0));
	backpackSize = DEFBACKPACKSIZE;
	constructionError = ERRORSIZE;
	if (items > 0)
	{
		for (int i = 0; i < items; i++)
		{
			itemTable.push_back(make_pair(rand() % (i + 1), rand() % (i + 1)));
		}
	}
	else
	{
		for (int i = 0; i < DEFITEMCOUNT; i++)
		{
			itemTable.push_back(make_pair(rand() % (i + 1), rand() % (i + 1)));
		}
	}


};

CKnapsackProblem::CKnapsackProblem(int items, double size) {
	srand(time(0));
	if (items > 0 && size > 0)
	{
		backpackSize = size;
		for (int i = 0; i < items; i++)
		{
			itemTable.push_back(make_pair(rand() % (i + 1), rand() % (i + 1)));
		}
	}
	else if(items > 0)
	{
		backpackSize = DEFBACKPACKSIZE;
		constructionError = ERRORSIZE;
		for (int i = 0; i < items; i++)
		{
			itemTable.push_back(make_pair(rand() % (i + 1), rand() % (i + 1)));
		}
	}
	else
	{
		backpackSize = DEFBACKPACKSIZE;
		constructionError = ERRORSIZE;
		for (int i = 0; i < DEFITEMCOUNT; i++)
		{
			itemTable.push_back(make_pair(rand() % (i + 1), rand() % (i + 1)));
		}
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
//*/

/*
double CKnapsackProblem::getAnswerValue(vector<bool>* answer)
{
	double result = 0;
	double size = 0;
	int iter = 0;
	//if answer is longer than backpack than the too long records are ignored:
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
//*/