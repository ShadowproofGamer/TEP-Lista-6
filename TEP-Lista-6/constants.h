#pragma once
#include <vector>
#include <tuple>
#include <iostream>
#include <fstream>
#include <istream>
#include <ostream>
#include "CMySmartPointer.h"
#include "CRefCounter.h"


//CKnapsackProblem CONSTANTS AND ERRORS:
#define DEFITEMCOUNT 50
#define DEFBACKPACKSIZE 300 
//CONSTRUCTOR ERROR CODES:
#define ERRORSIZE -1
#define ERRORVECTOR -2
#define ERRORBOTH -3
//FILE ERROR CODES:
#define FILENOTOPEN -10
#define FILEWRONGHEADER -11
#define FILECORRUPTED -12
//ANSWER RETURNING ERROR CODES:
#define ANSWERTOOLONG -20
//CGENETICALGORITHM DEFAULT VALUES:
#define DEFPOPULATION 1000
#define DEFCROSSPROBABILITY 0.7
#define DEFMUTATEPROBABILITY 0.03
//CGENETICALGORITHM OPTIMIZATION DEFAULT VALUES
#define DEFTIME 1*20
#define DEFMUTATEPERCENT 0.1

