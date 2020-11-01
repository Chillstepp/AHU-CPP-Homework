#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED

#include<vector>
#include<random>
using namespace std;
void CreateNoiseData(vector<pair<double,double>>&data)
{
    double sum=0;
    for(int i=0;i<data.size();i++)
    {
        sum+=data[i].first;
    }
    default_random_engine generator;
    normal_distribution<double>dist;
    int Data_Size=data.size();
    for(int i=0;i<Data_Size;i++)
    {
        data[i].second=data[i].second+dist(generator);
    }
    return;
}

#endif // COMPLEX_H_INCLUDED
