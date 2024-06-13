#ifndef KNAPSACK_SOLVER

#define KNAPSACK_SOLVER 1

#include <iostream>
#include <vector>

using namespace std;

namespace Knapsack
{
    struct Item 
    {
        int value;
        int weight;
    };

    class KnapsackSolver
    {
        int W, n, maxWeight;
        const vector<int> weights, values;

        public:

            KnapsackSolver()
            {

            }
            virtual ~KnapsackSolver() = default;

            KnapsackSolver operator=(const KnapsackSolver &k);

            vector<vector<int>> PDMatrix(int W, const vector<int>& weights, const vector<int>& values, int n);
            vector<int> PDResult(vector<vector<int>> dp, const vector<int>& weights, const vector<int>& values, int W, int n);
            int getMaxResultPd(vector<vector<int>> dp, int W, int n);
            int bruteForce(const std::vector<Item>& items, int maxWeight, int index); 

    };

};

#endif