#include <iostream>
#include <algorithm>
using namespace std;

float squaRoot(int num,int p)
{
    int s=0;
    int e=num;
    float ans;
    while(s<=e)
    {
        int mid=(s+e)>>1;
        if(mid*mid > num)
            e=mid-1;
        else if(mid*mid < num)
        {
            s=mid+1;
            ans=mid;
        }
        else            //mid*mid == num
        {
            ans=mid;
            break;
        }
    }

    //precision
    float inc=0.1;
    for(int i=1;i<=p;i++)
    {
        while(ans*ans<=num)
            ans+=inc;

        ans=ans-inc;
        inc/=10;
    }

    return ans;
}

int main() {
    int n,p;        //p is precision
    cin>>n>>p;
    cout<<squaRoot(n,p);

	return 0;
}
