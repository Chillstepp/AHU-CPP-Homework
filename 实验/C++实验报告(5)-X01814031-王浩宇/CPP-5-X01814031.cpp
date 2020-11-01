//Chillstep ^_^
#include<bits/stdc++.h>
using namespace std;

namespace Numeric
{
    //gcd函数
    int gcd(int x,int y){return y==0?x:gcd(y,x%y);}//求最大公因数
    //Rational类
    class Rational
    {
    private:
        int numerator;//分子
        int denominator;//分母
    public:
        //编写默认构造函数，构造一个有理数0;
        Rational():numerator(0),denominator(1){}
        //编写带参数列表的构造函数，要求使用初始化列表；
        Rational(int _numerator,int _denominator=1):numerator(_numerator),denominator(_denominator){}
        //编写复制构造函数；
        Rational(const Rational &v):numerator(v.numerator),denominator(v.denominator){}
        //编写赋值操作=
        Rational &operator=(const Rational &v)
        {
            if (this != &v)
            {
                numerator = v.numerator;
                denominator = v.denominator;
            }
            return *this;
        }
        //Rational类的化简
        Rational Simplfy()
        {
            int temp=gcd(abs(numerator),abs(denominator));//求最大公因数
            if(numerator<0&&denominator<0)//如果分子分母都小于0
            {
                numerator=-numerator/temp;//同除最小公倍数的负值，使得分子分母同为正
                denominator=-denominator/temp;
            }
            else
            {
                numerator=numerator/temp;//同除最小公倍数
                denominator=denominator/temp;
            }
            return *this;
        }
        //编写四个友元函数add、sub、mul、div
        //Rational加法
        friend Rational operator+(const Rational &a,const Rational &b)
        {
            int n=a.numerator*b.denominator+b.numerator*a.denominator;//分子
            int d=a.denominator*b.denominator;//分母
            return Rational(n,d).Simplfy();//得到分式并化简
        }
        //Rational减法
        friend Rational operator-(const Rational &a,const Rational &b)
        {
            int n=a.numerator*b.denominator-b.numerator*a.denominator;//分子
            int d=a.denominator*b.denominator;//分母
            return Rational(n,d).Simplfy();//得到分式并化简
        }
        //Rational乘法
        friend Rational operator*(const Rational &a,const Rational &b)
        {
            int n=a.numerator*b.numerator;//分子
            int d=a.denominator*b.denominator;//分母
            return Rational(n,d).Simplfy();//得到分式并化简
        }
        //Rational除法
        friend Rational operator/(const Rational &a,const Rational &b)
        {
            int n=a.numerator*b.denominator;//分子
            int d=a.denominator*b.numerator;//分母
            return Rational(n,d).Simplfy();//得到分式并化简
        }
    public:
        //编写友元函数lessThan，比较两个有理数的大小
        friend bool lessThan(const Rational &a,const Rational &b)
        {
            Rational d=a-b;//两个有理数的差值
            if(d.numerator*d.denominator>=0) //如果差值的分式分子分母同号，说明差值大于0，a>=b
                return false;
            else                            //反之，说明差值小于0，a<b
                return true;
        }
        float GetValue(const Rational &v)const//获得有理数的值
        {
            return 1.0*v.numerator/v.denominator;
        }
        void disp()//显示有理数的分式，便于调试观察
        {
            cout<<"("<<numerator<<"/"<<denominator<<")";
        }
    };

}

int main()
{
    using namespace Numeric;
    srand(time(0));


    //Test:a+b=c
    Rational a(rand()%15,rand()%15+1);
    Rational b(rand()%15,rand()%15+1);
    Rational c=a+b;
    a.disp();
    cout<<" + ";
    b.disp();
    cout<<" = ";
    c.disp();
    cout<<endl;

    //Test:b-a=c
    c=b-a;
    a.disp();
    cout<<" + ";
    b.disp();
    cout<<" = ";
    c.disp();
    cout<<endl;

    //Test:e=t*d
    Rational t(rand()%15+1);
    Rational d(rand()%15+1,rand()%15+1);
    Rational e=t*d;
    t.disp();
    cout<<" * ";
    d.disp();
    cout<<" = ";
    e.disp();
    cout<<endl;

    //Test:f=g/h;
    Rational g(rand()%15+1,rand()%15+1);
    Rational h(rand()%15+1,rand()%15+1);
    Rational f=g/h;
    g.disp();
    cout<<" / ";
    h.disp();
    cout<<" = ";
    f.disp();
    cout<<endl;

    //Test:Bubble Sorting
    vector<Rational>s;
    for(int i=1;i<=10;i++)//生成10个有理数
    {
        int n=rand()%15+1;
        int d=rand()%15+1;
        Rational tep(n,d);
        s.push_back(Rational(tep));
    }
    for (size_t i=0;i<s.size()-1;i++)//Bubble Sorting
    {
        for (size_t j=0;j<s.size()-1-i;j++)
        {
            if (!lessThan(s[j],s[j+1]))
            {
                Rational temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
            }
        }
	}
    for(size_t i=0;i<s.size();i++)
    {
        s[i].Simplfy().disp();
        cout<<"  ";
    }
    cout<<endl;


    return 0;
}
