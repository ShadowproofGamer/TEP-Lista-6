#pragma once
#include "constants.h"
#include "CGeneticAlgorithm.h"
#include "CIndividual.h"
#include "CKnapsackProblem.h"
namespace runner {
	static void runProgram(string filePath, int pop, double cross, double mutate)
	{
		CKnapsackProblem* algo = new CKnapsackProblem(filePath); //() ||"Tekst.txt" || "Tekst1.txt" - best 19
		CGeneticAlgorithm mainAlgo = CGeneticAlgorithm(pop, cross, mutate, algo);
		mainAlgo.runOptimization();
		delete algo;
	};
	static void runProgram(string filePath)
	{
		CKnapsackProblem* algo = new CKnapsackProblem(filePath); //() ||"Tekst.txt" || "Tekst1.txt" - best 19
		CGeneticAlgorithm mainAlgo = CGeneticAlgorithm(algo);
		mainAlgo.runOptimization();
		delete algo;
	};
	static void runProgram(int pop, double cross, double mutate)
	{
		CKnapsackProblem* algo = new CKnapsackProblem(); //() ||"Tekst.txt" || "Tekst1.txt" - best 19
		CGeneticAlgorithm mainAlgo = CGeneticAlgorithm(pop, cross, mutate, algo);
		mainAlgo.runOptimization();
		delete algo;
	};
	static void runProgram()
	{
		CKnapsackProblem* algo = new CKnapsackProblem(); //() ||"Tekst.txt" || "Tekst1.txt" - best 19
		CGeneticAlgorithm mainAlgo = CGeneticAlgorithm(algo);
		mainAlgo.runOptimization();
		delete algo;
	};
}

