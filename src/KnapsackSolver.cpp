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
    vector<int> result;

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

    //search solution

    int col = W;

    for(int i = n; i >= 1; i--)
    {
        cout<<dp[i][col]<<endl;

        if(dp[i][col] > dp[i - 1][col])
        {
            result.push_back(i);

            col -= weights[i];   
        }
        else if(dp[i][col] == dp[i - 1][col])
            col--;

    }

    for(auto& i : result)
    {
        cout<<"i: "<<i<<endl;

    }

    return dp[n][W];
}
int KnapsackSolver::bruteForce(const std::vector<Item>& items, int maxWeight, int index) 
{
    if (index == (int)items.size() || maxWeight == 0) 
        return 0;

    if (items[index].weight > maxWeight)
        return this->bruteForce(items, maxWeight, index + 1);

    int includeItem = items[index].value + this->bruteForce(items, maxWeight - items[index].weight, index + 1);
    int excludeItem = this->bruteForce(items, maxWeight, index + 1);

    return max(includeItem, excludeItem);
}