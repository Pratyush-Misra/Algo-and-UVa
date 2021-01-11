/*
	author:    Pratyush
	created:   08.11.2020 14:16:12
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

ll dp[20][5][2];
string s;
ll solve(ll pos,ll cnt,bool tight){
	if(pos==sz(s))	return 1;
	if(dp[pos][cnt][tight] != -1)	return dp[pos][cnt][tight];
	ll ret = 0;
	ll en = tight?(s[pos]-'0'):9;
	for(ll i=0;i<=en;i++){
		ll upd_cnt = cnt + (i>0);		// updated_count
		if(upd_cnt <= 3)	ret += solve(pos+1,upd_cnt,tight&(i==en));
	}
	return dp[pos][cnt][tight]=ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	int t;	cin>>t;
	while(t--){
		ll l,r;
		cin>>l>>r;
		memset(dp,-1,sizeof dp);
		s = to_string(r);
		ll ans = solve(0,0,1);
		l--;
		s = to_string(l);
		memset(dp,-1,sizeof dp);
		ans -= solve(0,0,1);
		cout<<ans<<endl;
	}

#ifdef LOCAL_DEFINE
	cerr << endl <<"Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s" << endl;
#endif
	return 0;
}
