#pragma once

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <iomanip>
#include <math.h>
#include <vector>
#include <random>
using namespace std;
#define pi acos(-1)

class point
{
private:
    double x;
    double y;
public:
    point():x(0),y(0){}
    point(const double _x,const double _y)
    {
        x=_x;
        y=_y;
    }
    point(const point &v)
    {
        x=v.x;
        y=v.y;
    }
    point &operator=(const point &v)
    {
        if(this!=&v)
        this->x=v.x;
        this->y=v.y;
        return *this;
    }
public:
    double getter(int v)const
    {
        if(v==1) return x;
        else return y;
    }
    point setter(const point v)
    {
        this->x=v.x;
        this->y=v.y;
        return *this;
    }
};

class Line
{
private:
    double a;
    double b;
    double c;
public:
    Line():a(0),b(1),c(0){}
    Line(const double _a,const double _b,const double _c)
    {
        a=_a;
        b=_b;
        c=_c;
    }
    Line(const Line &v)
    {
        a=v.a;
        b=v.b;
        c=v.c;
    }
    Line &operator=(const Line &v)
    {
        this->a=v.a;
        this->b=v.b;
        this->c=v.c;
        return *this;
    }
public:
    double GetLineTheta()
    {
        if(a==0&&b>0) return pi/2;
        if(a==0&&b<0) return pi/2;
        return atan(-b/a);
    }
    double GetParameter(const int v)
    {
        if(v==1) return a;
        else if(v==2) return b;
        else return c;
    }
    double CalcDistance(point v)
    {
        return fabs(a*v.getter(2)+b*v.getter(1)+c)/sqrt(a*a+b*b);
    }
    bool IsOnLine(point v)
    {
        if(a*v.getter(1)+b*v.getter(2)+c<1e-4)
            return  true;
        else
            return false;
    }
};


vector<point> CreateData(Line v,int cnt);

Line FitLine(vector<point>data);

double CalcDistance(Line v,vector<point>data);
