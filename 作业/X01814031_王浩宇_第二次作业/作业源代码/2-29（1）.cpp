//Chillstep ^_^
#include<bits/stdc++.h>
using namespace std;

bool is_prime(int x)
{
    if(x==1) return false;
    for(int i=2;i<=x-1;i++)
    {
        if(x%i==0) return false;
    }
    return true;
}
int main()
{
    for(int i=1;i<=100;i++)
    {
        if(is_prime(i)==true)
            cout<<i<<" ";
    }
    return 0;
}