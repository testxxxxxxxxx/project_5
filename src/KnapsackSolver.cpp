#include <iostream>
#include "../include/KnapsackSolver.hpp"

using namespace std;
using namespace Knapsack;

KnapsackSolver KnapsackSolver::operator=(const KnapsackSolver &k)
{

    return KnapsackSolver();
}
int KnapsackSolver::PD(int W, const vector<int>& weights, const vector<int>& values, int n) 
{    
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; ++i) 
    {
        for (int w = 0; w <= W; ++w) 
        {
            if (weights[i - 1] <= w)
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            else 
                dp[i][w] = dp[i - 1][w];
        }

    }

    return dp[n][W];
}
int KnapsackSolver::bruteForce(const std::vector<Item>& items, int maxWeight, int index) 
{
    if (index == items.size() || maxWeight == 0) 
        return 0;

    if (items[index].weight > maxWeight)
        return this->bruteForce(items, maxWeight, index + 1);

    int includeItem = items[index].value + this->bruteForce(items, maxWeight - items[index].weight, index + 1);
    int excludeItem = this->bruteForce(items, maxWeight, index + 1);

    return max(includeItem, excludeItem);
}