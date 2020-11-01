#include "PointAndLine.h"


vector<point> CreateData(Line v,int cnt)
{
    vector<point>data;
    default_random_engine generator;
    normal_distribution<double>dist;
    for(int i=1;i<=cnt;i++)
    {
        double x0=rand()%150;
        double a=v.GetParameter(1);
        double b=v.GetParameter(2);
        double c=v.GetParameter(3);
        double y0=-b*x0/a-c/a+dist(generator);
        point temp(x0,y0);
        data.push_back(temp);
    }
    return data;
}

Line FitLine(vector<point>data)
{
    double sigma_xy=0,sigma_x=0,sigma_y=0,sigma_x2=0,average_x=0,average_y=0;
    for(int i=0;i<(int)data.size();i++)
    {
        sigma_xy+=data[i].getter(1)*data[i].getter(2);
        sigma_x+=data[i].getter(1);
        sigma_y+=data[i].getter(2);
        sigma_x2+=data[i].getter(1)*data[i].getter(1);
    }
    int N=data.size();
    average_x=sigma_x/N;
    average_y=sigma_y/N;
    double a=(N*sigma_xy-sigma_x*sigma_y)/(N*sigma_x2-sigma_x*sigma_x);
    double b=average_y-a*average_x;
    Line ans(1,-a,-b);
    return ans;
}

double CalcDistance(Line v,vector<point>data)
{
    double dis=0;
    for(int i=0;i<(int)data.size();i++)
    {
        dis+=v.CalcDistance(data[i]);
    }
    dis=dis/(int)data.size();
    return dis;
}

