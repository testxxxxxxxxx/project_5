#include <iostream>
#include <vector>
#include "../include/KnapsackSolver.hpp"
#include <cstring>

using namespace std;
using namespace Knapsack;

int main(int argc, char *argv[])
{
    if(!argv[1] || (strcmp(argv[1], "--PD") != 0 && strcmp(argv[1], "--bruteForce") != 0))
    {
        cout<<"Error"<<endl;

        return 0;
    }

    vector<int> weights, values;
    int weight = 0;
    int value = 0;
    int capacity = 0;
    int n = 0;

    cout<<"capacity>";
    cin>>capacity;

    cout<<"n>";
    cin>>n;

    for(int i = 1; i <= n; i++)
    {
        cout<<"w"<<i<<">";
        cin>>weight;

        weights.push_back(weight);

    }

    for(int i = 1; i <= n; i++)
    {
        cout<<"p"<<i<<">";
        cin>>value;

        values.push_back(value);

    }

    KnapsackSolver *knapsackSolver = new KnapsackSolver();

    vector<vector<int>> pdMatrix;
    vector<int> resultKnapsack;

    if(strcmp(argv[1], "--PD") == 0)
    {
        pdMatrix = knapsackSolver->PDMatrix(capacity, weights, values, n);
        resultKnapsack = knapsackSolver->PDResult(pdMatrix, weights, values, capacity, n);

        cout<<"Value: "<<knapsackSolver->getMaxResultPd(pdMatrix, capacity, n)<<endl;
        cout<<"Result:";

        for(auto& i : resultKnapsack)
        {
            cout<<" "<<i;

        }

        cout<<endl;

    }
    else if(strcmp(argv[1], "--bruteForce") == 0)
    {

    }
    else
        cout<<"Error"<<endl;

    return 0;
}