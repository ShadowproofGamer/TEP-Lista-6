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
#define DEFITEMCOUNT 10
#define DEFBACKPACKSIZE 10 
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
#define DEFCROSSPROBABILITY 0.4
#define DEFMUTATEPROBABILITY 0.3
//CGENETICALGORITHM OPTIMIZATION DEFAULT VALUES
#define DEFTIME 1*60
#define DEFMUTATEPERCENT 0.1

