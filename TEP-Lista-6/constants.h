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