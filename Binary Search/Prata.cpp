#include <iostream>
#include <algorithm>
using namespace std;

bool isPossible(int cook[],int p,int c,int time)
{
    int prata=0;
    for(int i=0;i<c;i++)
    {
        int cookTime=0;
        int cnt=1;
        while(true)
        {
            cookTime+=(cnt*cook[i]);
            if(cookTime>time)
                break;
            else
            {
                prata++;
                cnt++;
                if(prata>=p)
                    return true;
            }
        }
    }
    return false;
}

int minTime(int cook[],int p,int c)
{
    int s=0;
    int e=cook[c-1]*(p*(p+1))/2;
    int ans;
    while(s<=e)
    {
        int midTime=(s+e)/2;
        if(isPossible(cook,p,c,midTime))
        {
            ans=midTime;
            e=midTime-1;
        }
        else
            s=midTime+1;
    }
    return ans;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int p,c;            //p is number of prata
        cin>>p>>c;          //c is number of cooks
        int cook[50];       //rank of cook
        for(int i=0;i<c;i++)
            cin>>cook[i];
        sort(cook,cook+c);
        cout<<minTime(cook,p,c)<<endl;
    }

    return 0;
}
