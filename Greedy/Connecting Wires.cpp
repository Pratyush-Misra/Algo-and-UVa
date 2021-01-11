#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#define endl '\n'
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

	int n,black[100],white[100];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>black[i];
	for(int i=0;i<n;i++)
		cin>>white[i];

	sort(black,black+n);
	sort(white,white+n);

	int res=0;
	for(int i=0;i<n;i++)
		res+=abs(black[i]-white[i]);

    cout<<"Minimum length of wire needed: "<<res<<endl;

	return 0;
}

