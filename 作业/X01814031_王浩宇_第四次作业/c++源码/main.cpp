//Chillstep =v=
#include<iostream>
#include<math.h>
#include<vector>
#include<random>
#include "CreateData.h"
#include "GradDescentIterration.h"
using namespace std;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>


int main()
{
    int n,m;
    vector<double>Coef;
    vector<pdd>data;
    cout<<"请输入多项式的次数n为多少:"<<endl;
    cin>>n;
    cout<<"请输入样本数据个数m为多少:"<<endl;
    cin>>m;
    cout<<"请输入"<<m<<"个样本数数据(格式为：横坐标x 纵坐标y):"<<endl;
    for(int i=0;i<m;i++)
    {
        double tempx,tempy;
        cin>>tempx>>tempy;
        data.push_back(make_pair(tempx,tempy));
    }
    cout<<"生成带有噪声且符合Gauss分布的数据："<<endl;
    CreateNoiseData(data);
    for(int i=0;i<(int)data.size();i++)
    {
        if(i%5==0) cout<<endl;
        cout<<"("<<data[i].first<<","<<data[i].second<<")"<<"  ";
        if(i==(int)data.size()-1) cout<<endl;
    }
    for(int i=0;i<=n;i++) Coef.push_back(0);
    iteration(Coef,data);
    cout<<endl;
    for(int i=0;i<(int)Coef.size();i++)
    {
        cout<<Coef[i]<<endl;
    }

    return 0;
}
/*
2
10
0 1
1 4
2 9
3 16
4 25
5 36
6 49
7 64
8 81
9 100


1
10
1 20
2 40
3 60
4 80
5 100
6 120
7 140
8 160
9 180
10 200

1
10
1 1020
2 1040
3 1060
4 1080
5 1100
6 1120
7 1140
8 1160
9 1180
10 1200
*/
