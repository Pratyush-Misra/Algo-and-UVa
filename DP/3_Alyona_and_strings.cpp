/*
	author:    Pratyush
	created:   24.09.2020 21:01:52
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
 
ll mod = 1e10+7;
string s,t;
//vt<vt<vt<vt<int>>>> dp(1005,vt<vt<vt<int>>>(1005,vt<vt<int>>(12,vt<int>(2,-1))));
ll dp[1005][1005][12][2];
ll solve(int n,int m,int k,int cont){
	if(!n or !m)	return 0;
	if(!k)	return 0;
	if(dp[n][m][k][cont]!=(-1))	return dp[n][m][k][cont];
	ll ans=INT_MIN;
	umax(ans,max(solve(n-1,m,k-cont,0),solve(n,m-1,k-cont,0)));
	if(s[n-1] == t[m-1])	umax(ans,1 + max(solve(n-1,m-1,k,1),solve(n-1,m-1,k-1,0)));
	return dp[n][m][k][cont]=ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	memset(dp,-1,sizeof dp);
	int n,m,k;
	cin>>n>>m>>k;
	cin>>s>>t;
	cout << solve(n,m,k,0) << endl;
#ifdef LOCAL_DEFINE
	cerr << endl <<"Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s" << endl;
#endif
	return 0;
}
