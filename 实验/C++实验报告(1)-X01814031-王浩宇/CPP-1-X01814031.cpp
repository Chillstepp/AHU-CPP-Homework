#include <bits/stdc++.h>
using namespace std;

typedef struct
{
    bool RealBoot = false;
    int NumOfRoot = 0;
    double res1,res2;
}AnsType;

AnsType SolQuadEqn(double a, double b, double c)
{
    AnsType Solution;

    if(b*b-4*a*c<0)
    {
        Solution.RealBoot = false;
        return Solution;
    }
    else Solution.RealBoot = true;

    if(b*b-4*a*c==0) Solution.NumOfRoot=1;
    else Solution.NumOfRoot=2;

    Solution.res1 = (-b-sqrt(b*b-4*a*c))/2*a;
    Solution.res2 = (-b+sqrt(b*b-4*a*c))/2*a;
    return Solution;
}

int main()
{
    int a,b,c;
    cout<<"请输入ax^2+bx+c=0的系数a,b,c(空格隔开)"<<endl;
    cin>>a>>b>>c;

    while(a==0)
    {
        cout<<"该方程不是一元二次方程,请重新输入"<<endl;
        cout<<"请输入ax^2+bx+c=0的系数a,b,c(空格隔开)"<<endl;
        cin>>a>>b>>c;
    }
    AnsType Solution=SolQuadEqn(a,b,c);

    if(Solution.RealBoot == false)
        cout<<"该方程无实根。"<<endl;
    else
    {
        if(Solution.NumOfRoot==1) cout<<"该方程有1个根,为:x="<<Solution.res1<<endl;
        else cout<<"该方程有2个根,为:"<<"x1="<<Solution.res1<<"  x2="<<Solution.res2<<endl;
    }
    return 0;
}
