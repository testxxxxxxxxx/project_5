//Author: Marcin Wrzaskowski
//Index number: 160329

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
    int maxWeight = 0;

    cout<<"capacity>";
    cin>>capacity;

    cout<<"n>";
    cin>>n;

    vector<Item> items(n);

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

    if(strcmp(argv[1], "--bruteForce") == 0)
    {
        for(int i = 0; i <= n; i++)
        {
            items[i].weight = weights[i];
            items[i].value = values[i];

            if(weights[i] > maxWeight)
                maxWeight = weights[i];

        }

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

        for(int& i : resultKnapsack)
        {
            cout<<" "<<i;

        }

        cout<<endl;

    }
    else if(strcmp(argv[1], "--bruteForce") == 0)
    {
        cout<<"maxWeight: "<<maxWeight<<endl;

        vector<int> elements;

        int result = knapsackSolver->bruteForceResult(items, maxWeight);

        cout<<"Value: "<<result<<endl;

        elements = knapsackSolver->bruteForce(items, maxWeight);

        cout<<"Result:";    

        for(int& i : elements)
        {
            cout<<" "<<i + 1;

        }

        cout<<endl;

    }
    else
        cout<<"Error"<<endl;

    return 0;
}