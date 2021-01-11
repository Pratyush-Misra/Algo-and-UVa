#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;

bool compare(pair<int,int> a,pair<int,int> b){
	return a.second < b.second;
}

int max_activities(vector<pair<int,int>> v){
	sort(v.begin(),v.end(),compare);
	int ans=1;
	int e = v[0].second;
	int n=v.size();
	for(int i=1;i<n;i++){
		if(v[i].first>=e)
		{
			ans++;
			e=v[i].second;
		}
	}
	return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

	int t;
	cin>>t;
	vector<pair<int,int>> v;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			int a,b;
			cin>>a>>b;
			v.push_back({a,b});
		}
		cout<<max_activities(v)<<endl;
		v.clear();
	}

	return 0;
}

