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
	// building the sieve
	ll n = 3005;
	bitset<3005> sieve;		// all 1e7+5 values set to 0 initially by def
	sieve[2]=1;
	FOR(i,3,n+1,2) sieve[i]=1;
	for(ll i=3;i*i<=n;i+=2){
		if(sieve[i]){
			for(ll k=i*i;k<=n;k+=i)	sieve[k]=0;
		}
	}		

	int x,ans=0;
	cin>>x;
	FOR(i,1,x+1){
		set<int> s;
		for(int k=2;k<x;k++)	if(sieve[k] and i%k==0)	s.insert(k);	
		if(sz(s)==2)	ans++;
	}
	cout<<ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

#ifdef LOCAL_DEFINE
	//	freopen("input.txt","r",stdin);
	//	freopen("o.txt","w",stdout);
#endif

	int t=1;//	cin>>t;
	FOR(t) {
		//write("Case #", i+1, ": ");
		solve();	
	}

#ifdef LOCAL_DEFINE
	cerr << endl << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s" << endl;
#endif
	return 0;
}
