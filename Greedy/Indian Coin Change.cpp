#include <iostream>
#include <algorithm>
#include <string>
#define endl '\n'
using namespace std;

int make_change(int *a,int n,int money){
	int ans=0;
	while(money){
		int idx = upper_bound(a,a+n,money)-1-a;
		money-=a[idx];
		ans++;
	}
	return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

	int money;
	cin>>money;
	int amt[]={1,2,5,10,20,50,100,200,500,2000};
	int n=sizeof(amt)/sizeof(int);
	cout<<"Coins Needed: "<<make_change(amt,n,money);

	return 0;
}


