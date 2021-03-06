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
#define mp make_pair
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second

#define pii pair<int,int>
#define pll pair<ll,ll>

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
const int N = 1e5+5;


void solve(){
	//int n;	cin>>n;	vt<int> v(n);	FOR(n)	cin>>v[i];
	int n,x,y;
	cin>>n>>x>>y;
	
	// Method - 1 : Number theory
	int rem = n%(x+y);
	if(x<=rem and rem<=(x+y-1))	cout<<"A wins by picking "<<(rem<=y ? rem : rem-y)<<endl;
	else cout<<"A loses"<<endl;	

	// Method - 2 : Number theory
	auto ans = [&]{
		vt<int> dp(n+5,-1);		// single state enough
		FOR(i,x,y+1)	dp[i]=i;
		FOR(i,y+1,n+1){
			if(dp[i-x]!=-1 and dp[i-y]!=-1)	dp[i]=-1;
			else dp[i]=x;
		}
		return dp[n];
	};
	if(ans() != -1)	cout<<"A wins by picking "<<ans()<<endl;
	else cout<<"A loses"<<endl;

}

int main(){
	ios::sync_with_stdio(0);
	
	cin.tie(0);


#ifdef LOCAL_DEFINE
	//	freopen("input.txt","r",stdin);
	//	freopen("o.txt","w",stdout);
#endif

	int t=1;	cin>>t;
	FOR(t) {
		//write("Case #", i+1, ": ");
		solve();	
	}

#ifdef LOCAL_DEFINE
	cerr << endl << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s" << endl;
#endif
	return 0;
}
