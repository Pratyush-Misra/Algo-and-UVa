#include <iostream>
#include <algorithm>
using namespace std;

bool isPossible(int book[],int n,int c,int mid)
{
    int cntStud=1;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        if((sum+book[i])>mid)
        {
            cntStud++;
            sum=book[i];
            if(cntStud>c)
                return false;
        }
        else
            sum+=book[i];
    }
    return true;
}

int maxPageRead(int book[],int n,int c)
{
    if(n<c)
        return -1;
    else
    {
        int s=book[n-1];
        int e=0;
        for(int i=1;i<n;i++)
            e+=book[i];
        int ans=e;
        while(s<=e)
        {
            int mid=(s+e)>>1;
            cout<<mid<<endl;
            bool resIsPossible = isPossible(book,n,c,mid);
            if(resIsPossible)
            {
                ans=mid;        //or we can ans=min(ans,mid);
                e=mid-1;
            }
            else
                s=mid+1;
        }
        return ans;
    }
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int book[1000];
		int n,c;        //c is number of students
		cin>>n>>c;
		for(int i=0;i<n;i++)
			cin>>book[i];
        cout<<maxPageRead(book,n,c)<<endl;
	}
	return 0;
}
