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
    int countOfItems = 0;
    int weight = 0;
    int value = 0;
    int capacity = 0;
    int n = 0;

    cout<<"countOfItems>";
    cin>>countOfItems;

    cout<<"capacity>";
    cin>>capacity;

    cout<<"n>";
    cin>>n;

    for(int i = 0; i < countOfItems; i++)
    {
        cout<<"w"<<i<<">";
        cin>>weight;

        weights.push_back(weight);

    }

    for(int i = 0; i < countOfItems; i++)
    {
        cout<<"p"<<i<<">";
        cin>>value;

        values.push_back(value);

    }

    KnapsackSolver *knapsackSolver = new KnapsackSolver();

    if(strcmp(argv[1], "--PD") == 0)
        cout<<"Result: "<<knapsackSolver->PD(capacity, weights, values, n)<<endl;
    else if(strcmp(argv[1], "--bruteForce") == 0)
    {

    }
    else
        cout<<"Error"<<endl;

    return 0;
}