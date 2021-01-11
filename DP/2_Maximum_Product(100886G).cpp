/*
	author:    Pratyush
	created:   09.11.2020 10:40:03
*/	
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld long double
#define ar array
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
#define vt vector
#define pb push_back
#define fi first
#define se second
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()

#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define EACH(x, a) for (auto& x: a)

template<class T> bool umin(T& a, const T& b) {
	return b<a?a=b, 1:0;
}
template<class T> bool umax(T& a, const T& b) { 
	return a<b?a=b, 1:0;
} 

mt19937 mt_rng(chrono::steady_clock::now().time_since_epoch().count());

const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};

pair<ll,string> dp[20][2][2][2];
string a,b;
pair<ll,string> solve(ll pos,bool ta,bool tb,bool st){
	if(pos==sz(a))	return {1,""};
	if(dp[pos][ta][tb][st].fi	!= -1)	return dp[pos][ta][tb][st];
	ll pro=-1;
	string ans="";
	ll lb = ta?(a[pos]-'0'):0;
	ll ub = tb?(b[pos]-'0'):9;
	for(ll i=lb;i<=ub;i++){
		ll val = (st==0 and i==0)?1:i;
		auto dp_ans = solve(pos+1,ta&(i==lb),tb&(i==ub),st|(i>0));
		if(umax(pro,val * dp_ans.fi)){
			if(st or i){
				dp_ans.se.insert(0,1,i+'0');	
				ans=dp_ans.se;
			}
			else ans=dp_ans.se;
		}
	}
	return dp[pos][ta][tb][st]={pro,ans};
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	int t=1;//	cin>>t;
	while(t--){
		cin>>a>>b;
		a.insert(0,sz(b)-sz(a),'0');	
		FOR(i,20)	FOR(j,2)	FOR(k,2)	FOR(l,2)	dp[i][j][k][l].fi=-1;
		cout<<solve(0,1,1,0).se;
	}

#ifdef LOCAL_DEFINE
	cerr << endl <<"Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s" << endl;
#endif
	return 0;
}

