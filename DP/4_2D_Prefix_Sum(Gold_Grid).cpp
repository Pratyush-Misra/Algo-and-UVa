/*
	author:    Pratyush
	created:   18.09.2020 13:37:23
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

vt<vt<int>> dp(1005,vt<int>(1005,0));
int maxCoins(int n,int m){
	int ans=0;
	FOR(i,1,n){
		FOR(j,1,n){
			int op1=dp[i][j];
			int op2=dp[i][n]-dp[i][j];
			int op3=dp[n][j]-dp[i][j];
			int op4=m-op1-op2-op3;
			umax(ans,min(min(op1,op2),min(op3,op4)));
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	int n,m;
	cin>>n>>m;
	FOR(m){
		int x,y;
		cin>>x>>y;
		dp[x][y]=1;
	}
	FOR(i,1,n+1)	FOR(j,1,m+1)	dp[i][j]+=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
	FOR(i,1,n+1){
		FOR(j,1,n+1)	cout<<dp[i][j]<<' ';
		cout<<endl;	
	}
	cout<<maxCoins(n,m);

#ifdef LOCAL_DEFINE
	cerr << endl <<"Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s" << endl;
#endif
	return 0;
}
