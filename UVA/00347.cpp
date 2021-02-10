#include <bits/stdc++.h>
using namespace std;
 
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
 
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
#define fi first
#define se second
#define mp make_pair

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
 
template<class P,class Q> ll CEIL(const P& a,const Q& b){
	return (ll)ceil((a*1.0)/b);
}

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
const long long INF = 1e18;
const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

int M;
void solve(){
	//int n;	cin>>n;	vt<int> v(n);	FOR(n)	cin>>v[i];	
	while(M > 0 and M <= 999999999){
		// check different digit
		int tmp = M;
		vt<int> vis(10);
		vt<int> digit;
		bool ok = true;
		while(tmp){
			int last = tmp % 10;
			if(vis[last] or !last){
				ok = false;
				break;
			}
			vis[last] = 1;
			digit.pb(last);
			tmp /= 10;
		}
		if(!ok){
			M++;
			continue;
		}
		reverse(all(digit));
		fill(all(vis),0);
		int f = 0,ctr=0;
		ok = true;
		int len = sz(digit);
		FOR(len){
			if(vis[f]){
				ok = false;
				break;
			}
			vis[f] = 1;
			f = (f + digit[f] % len) % len; 
			ctr++;
		}
		if(ok and !f and ctr == len){
			cout << M << endl;
			return;
		}
		M++;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int i = 1;
	while(cin >> M) {
		if(!M)	break;
		cout << "Case " <<  i++ << ": ";
		solve();
	}


#ifdef LOCAL_DEFINE
	cerr << endl << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s" << endl;
#endif
	return 0;
}