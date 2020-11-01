//Chillstep ^_^
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tot=0;
    for(int i=0;i<(1<<5);i++)
    {
        int cnt=0;
        for(int j=0;j<5;j++)
        {
             if((i>>j)&1==1) cnt++;
        }
        if(cnt==3)
        {
            tot++;
            if((i>>0)&1==1) cout<<"red ";
            if((i>>1)&1==1) cout<<"yellow ";
            if((i>>2)&1==1) cout<<"blue ";
            if((i>>3)&1==1) cout<<"white ";
            if((i>>4)&1==1) cout<<"black ";
            puts("");
        }
    }
    cout<<"the number of total solutions:"<<tot<<endl;
    return 0;
}