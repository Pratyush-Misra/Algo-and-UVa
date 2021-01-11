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

	int t;
	cin>>t;
	while(t--){
		int w,h,n,maxH=0,maxW=0;
		cin>>w>>h>>n;
		int x[40010]={0};
		int y[40010]={0};
		for(int i=0;i<n;i++)
			cin>>x[i]>>y[i];
		// for max width
		sort(x,x+n);
		sort(y,y+n);
		maxW = max(maxW,max( (x[0]-1) , (w-x[n-1]) ));
		maxH = max(maxH,max( (y[0]-1) , (h-y[n-1]) ));
		for(int i=1;i<n;i++)
		{
			maxW = max(maxW,x[i]-x[i-1]-1);
			maxH = max(maxH,y[i]-y[i-1]-1);
		}
		cout<<maxW*maxH<<endl;
	}

	return 0;
}


