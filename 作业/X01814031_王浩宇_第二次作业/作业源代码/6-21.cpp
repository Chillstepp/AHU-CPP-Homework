//Chillstep ^_^
#include<bits/stdc++.h>
using namespace std;
int cal(string a)
{
    int letter=0;
    for(int i=0;i<a.size();i++)
    {
        if((a[i]>='a'&&a[i]<='z')||(a[i]>='A'&&a[i]<='Z'))
            letter++;
    }
    return letter;
}
int main()
{
    string s;
    cin>>s;
    cout<<cal(s)<<endl;
    return 0;
}
