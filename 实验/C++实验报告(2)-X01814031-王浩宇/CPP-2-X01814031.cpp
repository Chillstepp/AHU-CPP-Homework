#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <iomanip>
#include <math.h>
using namespace std;
typedef struct
{
    bool IsLegal;//是否合法
    double result;
}AnsType;

AnsType f1(const double x)
{
    AnsType ans;
    if(x>1||x<-1) ans.IsLegal=false;//如果不在定义域，记为不合法
    else ans.IsLegal=true;//若在定义域内，记为合法
    ans.result=sqrt(1-x*x);//带入参数后的函数值
    return ans;
}

AnsType f2(const double x)
{
    AnsType ans;
    ans.IsLegal=true;//因为定义域为实数，记为合法
    ans.result=sin(x);//带入参数后的函数值
    return ans;
}

const double delta=1e-4;
const double pi=acos(-1);
typedef AnsType (*Func)(const double); //函数指针

AnsType Calc_integral(Func f,const double l,const double r)//计算积分函数
{
    AnsType ans;
    double sum=0;
    for(double i=l;i<=r;i+=delta)//将积分分为许多段进行计算
    {
        if(f(i).IsLegal==true)//如果代入得参数是合法的，积分累计上此次的结果
             sum+=f(i).result*delta;
        else
        {
            ans.IsLegal=false;//如果带入的参数不合法则结束
            return ans;
        }
    }
    ans.IsLegal=true;//答案合法
    ans.result=sum;//最终积分结果
    return ans;
}

int main()
{
    cout.setf(ios::fixed,ios::floatfield);//十进制计数法，不用科学计数法
	cout.precision(2);//保留2位小数
    AnsType ans;

    ans=Calc_integral(f1,-1,1);
    if(ans.IsLegal==true)
        cout<<"√(1-x^2)函数在[-1，1]上的积分为"<<ans.result<<endl;
    else  cout<<"√(1-x^2)积分的定义域错误"<<endl;

    ans=Calc_integral(f1,-2,1);
    if(ans.IsLegal==true)
        cout<<"√(1-x^2)在[-2，1]上的积分为"<<ans.result<<endl;
    else  cout<<"√(1-x^2)积分的定义域错误"<<endl;

    ans=Calc_integral(f1,0,1);
    if(ans.IsLegal==true)
        cout<<"√(1-x^2)在[0，1]上的积分为"<<ans.result<<endl;
    else  cout<<"√(1-x^2)积分的定义域错误"<<endl;

    ans=Calc_integral(f2,-pi,pi);
    if(ans.IsLegal==true)
        cout<<"sin(x)在[-pi，pi]上的积分为"<<ans.result<<endl;
    else  cout<<"sin(x)积分的定义域错误"<<endl;

    AnsType ans2=Calc_integral(f2,0,pi);
    if(ans2.IsLegal==true)
        cout<<"sin(x)在[0，pi]上的积分为"<<ans2.result<<endl;
    else  cout<<"sin(x)积分的定义域错误"<<endl;

    ans=Calc_integral(f2,0,pi/2.0);
    if(ans.IsLegal==true)
        cout<<"sin(x)函数在[0，pi/2]上的积分为"<<ans.result<<endl;
    else  cout<<"sin(x)积分的定义域错误"<<endl;


    return 0;
}
