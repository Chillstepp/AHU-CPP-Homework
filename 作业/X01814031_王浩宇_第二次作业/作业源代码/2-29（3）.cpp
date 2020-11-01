//Chillstep ^_^
#include<bits/stdc++.h>
using namespace std;
bool is_prime(int x)
{
    if(x==1) return false;
    if(x==2) return true;
    int i=2;
    do
    {
        if(x%i==0) return false;
        i++;
    }while(i<=x-1);
    return true;
}
int main()
{
    int i=1;
    do
    {
        if(is_prime(i)==true)
            cout<<i<<" ";
        i++;
    }while(i<=100);
    return 0;
}
