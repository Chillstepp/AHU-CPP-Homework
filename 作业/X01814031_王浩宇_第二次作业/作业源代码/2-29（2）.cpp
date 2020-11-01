//Chillstep ^_^
#include<bits/stdc++.h>
using namespace std;
bool is_prime(int x)
{
    if(x==1) return false;
    if(x==2) return true;
    int i=2;
    while(x%i!=0)
    {
        i++;
        if(i>=sqrt(x)) return true;
    }
    return false;
}
int main()
{
    int i=1;
    while(i<=100)
    {
        if(is_prime(i)==true)
            cout<<i<<" ";
        i++;
    }
    return 0;
}
