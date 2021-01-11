#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#define endl '\n'
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

	while(1){
		int a[10000]={0};
		int n,load=0,ans=0;
		cin>>n;
		if(n==-1)	break;
	    for(int i=0;i<n;i++)
		{
			cin>>a[i];
			load+=a[i];
		}
		if(load%n!=0)
		{
			cout<<(-1)<<endl;
			continue;
		}
		else load=load/n;
		int trans=0,sum=0;
		for(int i=0;i<n;i++){
			sum+=a[i];
			trans=abs(load*(i+1)-sum);
			ans=max(ans,trans);
		}
		cout<<ans<<endl;
	}

	return 0;
}


