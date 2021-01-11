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

	ll n,d;
	cin>>n>>d;
	ll *a=new ll[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	ll cnt=0;
	for(ll i=0;i<n and (i+1)<n;){
		if((a[i+1]-a[i])<=d)
		{
			cnt++;
			i=i+2;
		}
		else i=i+1;
	}
	cout<<cnt;

	delete []a;
	return 0;
}


