#include <iostream>
#include <algorithm>
using namespace std;

bool canPlaceCows(int stall[],int n,int c,int minSep)
{
	int cnt=1;      //cows ka count
	int lastCow=stall[0];
	for(int i=1;i<n;i++)
    {
        if((stall[i]-lastCow)>=minSep)
        {
            lastCow=stall[i];
            cnt++;
            if(cnt==c)
                return true;
        }
    }
    return false;
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int stall[100000];
		int n,c;
		cin>>n>>c;
		for(int i=0;i<n;i++)
			cin>>stall[i];
		sort(stall,stall+n);

		int s=0;
		int e=(stall[n-1]-stall[0]);
		int ans=0;
		while(s<=e)
        {
            int mid=(s+e)>>1;       //min separation
            bool resCanPlaceCows = canPlaceCows(stall,n,c,mid);
            if(resCanPlaceCows)     //if we can place cows for this separation
            {
                ans=mid;
                s=mid+1;
            }
            else
                e=mid-1;
        }
        cout<<ans<<endl;
	}
	return 0;
}
