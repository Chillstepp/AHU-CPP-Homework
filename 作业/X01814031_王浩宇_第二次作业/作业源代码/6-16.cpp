//Chillstep ^_^
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a;
    int *p=&a;
    int &r=a;
    *p=10;
    cout<<a<<endl;
    r=5;
    cout<<a<<endl;
    return 0;
}