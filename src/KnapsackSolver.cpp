#include <iostream>
#include "../include/KnapsackSolver.hpp"

using namespace std;
using namespace Knapsack;

KnapsackSolver KnapsackSolver::operator=(const KnapsackSolver &k)
{

    return KnapsackSolver();
}
vector<vector<int>> KnapsackSolver::PDMatrix(int W, const vector<int>& weights, const vector<int>& values, int n) 
{    
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    //build dynamic programming matrix

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

    return dp;
}
vector<int> KnapsackSolver::PDResult(vector<vector<int>> dp, const vector<int>& weights, const vector<int>& values, int W, int n)
{
    //search solution

    vector<int> result;

    int col = W;

    for(int i = n; i >= 1; i--)
    {
        if(dp[i][col] > dp[i - 1][col])
        {
            result.push_back(i);

            col -= weights[i];   
        }
        else if(dp[i][col] == dp[i - 1][col])
            col--;

    }

    return result;
}
int KnapsackSolver::getMaxResultPd(vector<vector<int>> dp, int W, int n)
{

    return dp[n][W];
}
vector<int> KnapsackSolver::bruteForce(const vector<Item>& items, int maxWeight) 
{
    Result result = this->bruteForceHelper(items, maxWeight, 0);
    return result.selectedIndices;
}
int KnapsackSolver::bruteForceResult(const vector<Item>& items, int maxWeight)
{
    Result result = this->bruteForceHelper(items, maxWeight, 0);

    return result.value;
}
Result KnapsackSolver::bruteForceHelper(const std::vector<Item>& items, int maxWeight, int index) 
{
    if (index == (int)items.size() || maxWeight == 0)
         return {0, {}};

    if (items[index].weight > maxWeight)
            return this->bruteForceHelper(items, maxWeight, index + 1);

    Result includeResult = this->bruteForceHelper(items, maxWeight - items[index].weight, index + 1);
    includeResult.value += items[index].value;
    includeResult.selectedIndices.push_back(index);

    Result excludeResult = this->bruteForceHelper(items, maxWeight, index + 1);

    if (includeResult.value > excludeResult.value) 
            return includeResult;
    else 
            return excludeResult;

}