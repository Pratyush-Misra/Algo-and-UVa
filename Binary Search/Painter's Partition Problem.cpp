#include <iostream>+
#include <algorithm>
#define ll long long int
using namespace std;

bool isPossible(ll dim[],int n,int b,ll midTime)
{
    ll sumTime=0;
    int boards=0;
    int i=0;
    int painter=1;
    while(i<b)
    {
        if((sumTime==0 and (sumTime+dim[i])>midTime) or painter>n)
            return false;

        if((sumTime+dim[i])>midTime)
        {
            sumTime=0;
            painter++;
            --i;
        }
        else
        {
            sumTime+=dim[i];
            boards++;
            if(boards>=b)
                return true;
        }
        i++;
    }
}

ll minTime(ll dim[],int n,int b)
{
    ll s=0;
    ll e=0;
    ll ans;
    for(int i=0;i<b;i++)
        e+=dim[i];
    while(s<=e)
    {
        ll midTime=(s+e)/2;
        if(isPossible(dim,n,b,midTime))
        {
            ans=midTime;
            e=midTime-1;
        }
        else
        {
            s=midTime+1;
        }
    }
    return ans;
}

int main()
{
    ll dim[10];
    ll n,b;
    cin>>n>>b;
    for(int i=0;i<b;i++)
        cin>>dim[i];
    for(int i=0;i<b;i++)
        cout<<dim[i]<<' ';
    cout<<endl;
    cout<<minTime(dim,n,b)<<endl;

    return 0;
}
