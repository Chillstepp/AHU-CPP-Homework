#include<iostream>
#include<math.h>
#include<vector>
#include<random>
using namespace std;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>

const double LearnRate=1e-5;//学习率
const double delta=1e-8;//计算梯度的delta
const double Accuracy=1e-6;
//int cnt=200000;//迭代次数

double CalcPolyn(vector<double>Coef,double x)
{
    double sum=Coef[0];
    for(int i=1;i<(int)Coef.size();i++)
    {
        sum+=Coef[i]*pow(x,i);
    }
    return sum;
}

double Calc_L_Theta(vector<double>Coef,vector<pdd>data)
{
    double sum=0;
    for(int i=0;i<(int)data.size();i++)
    {
        sum+=pow((CalcPolyn(Coef,data[i].first)-data[i].second),2);
    }
    double ans=sum/(int)data.size();
    return ans;
}

void GradDescent(vector<double>&Coef,vector<pdd>data)
{
    vector<double>TempCoef1=Coef;
    for(int i=0;i<(int)Coef.size();i++)
    {
        vector<double>TempCoef2=TempCoef1;
        TempCoef2[i]+=delta;
        double grad=(Calc_L_Theta(TempCoef2,data)-Calc_L_Theta(TempCoef1,data))/delta;
       // cout<<"grad"<<grad<<endl;
        Coef[i]-=grad*LearnRate;
    }
}

void iteration(vector<double>&Coef,vector<pdd>data)
{
    int cnt=1;
    vector<double>Temp=Coef;
    while(cnt++)
    {
        bool flag=1;
        GradDescent(Coef,data);

        for(int i=0;i<(int)Coef.size();i++)
        {
            if(fabs(Coef[i]-Temp[i])>Accuracy)
            {
                Temp=Coef;
                flag=0;
                break;
            }

        }
        if(flag==1)
        {
            cout<<"迭代次数为："<<cnt<<endl;
            break;
        }
    }
}
