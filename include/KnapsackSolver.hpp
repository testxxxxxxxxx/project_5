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
        int W, n;
        const vector<int> weights, values;

        public:

            KnapsackSolver()
            {

            }
            KnapsackSolver(int W, const vector<int>& weights, const vector<int>& values, int n): W(W), weights(weights), values(values)
            {

            }
            virtual ~KnapsackSolver() = default;

            KnapsackSolver operator=(const KnapsackSolver &k);

            int PD(int W, const vector<int>& weights, const vector<int>& values, int n);
            int bruteForce(const std::vector<Item>& items, int maxWeight, int index); 

    };

};

#endif