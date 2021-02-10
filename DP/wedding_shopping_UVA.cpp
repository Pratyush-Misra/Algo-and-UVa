#include <bits/stdc++.h>
using namespace std;
 
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds; 
template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long 
#define ld long double
#define ar array

#define vt vector
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define mp make_pair
#define pii pair<int,int>

#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define EACH(x, a) for (auto& x: a)
 
template<typename T>
void output_vector(vt<T>& v, int till_where = 0, int base_idx = 0){
	till_where = till_where ? till_where : sz(v);
	FOR(i,till_where)	cout << (v[i] + base_idx) << ' ';
	cout << endl;
}
 
template<class P,class Q> int CEIL(const P& a,const Q& b){
	return (int)ceil((a*1.0)/b);
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

/* Solution : 



*/
int M,C;
int price[25][25];	
vt<int> path;
// TOP DOWN DP Solution
int dp[205][25];
int spent(int money,int g){
	if(money < 0)	return -INF;
	if(g == C)	return M - money;		// visited all the shops(0 -> C-1) so amt spent = M - money
	if(dp[money][g] != -1)	return dp[money][g];
	int ans = -1;
	FOR(model, 1, price[g][0] + 1)
		umax(ans, spent(money-price[g][model], g+1));
	return dp[money][g] = ans;

	// a bit more optimisation can be that we can do
	// 1) remove money < 0 if condition because we can rather check if money - price of current model > 0
	// then only call further else earlier it was going into recursion overhead
	// if(g == C)	return M - money;		// visited all the shops(0 -> C-1) so amt spent = M - money
	// if(dp[money][g] != -1)	return dp[money][g];
	// int ans = -1;
	// FOR(i, 1, price[i][0] + 1)
	// 		if(money - price[g][i] >= 0)
	// 			umax(ans, spent(money-price[g][i], g+1));
	// return dp[money][g] = ans;
}

// BOTTOM UP DP Solution
bool dp2[25][205];
int spent2(){
	memset(dp2,false,sizeof dp2);
	// now marking true, each of the models that are reachable from the first shop
	FOR(g,1,price[0][0]+1)	if(M - price[0][g] >= 0)	dp2[0][M - price[0][g]] = true;	

	// now Bottom-Up movement for each of the left C-1 shops from idx 1 -> C-1
	FOR(g,1,C)
		FOR(money,M+1)	if(dp2[g-1][money] == true)		
			FOR(k,1,price[g][0] + 1)	if(money - price[g][k] >= 0)
					dp2[g][money - price[g][k]] = true;

	FOR(money,M+1)	if(dp2[C-1][money] == true)	return M-money;
	return -1;	// ie NO SOLUTION
}	

// Bottom Up DP Space Optimised
bool dp3[2][205];
int spent3(){
	memset(dp3,false,sizeof dp3);
	FOR(g,price[0][0] + 1)	if(M - price[0][g] >= 0)	dp3[0][M-price[0][g]] = true;

	FOR(shop,1,C)
		FOR(money,M+1)	if(dp3[(shop-1)%2][money] == true)
			FOR(model,1,price[shop][0]+1)	if(money - price[shop][model]>=0)
				dp3[shop%2][money - price[shop][model]] = true;

	FOR(money,M+1)	if(dp3[(C-1)%2][money] == true)	return M - money;
	return -1;
}

void solve(){
	memset(dp,-1,sizeof dp);
	cin >> M >> C;
	FOR(C){
		cin >> price[i][0];			// store K i.e. number of models in one shop in price[i][0];
		// now store the prices of the K models in price[i][1] -> price[i][K];
		FOR(pr,1,price[i][0]+1)	cin >> price[i][pr];
	} 
	cout << mp(spent(M,0), mp(spent2(),spent3())) << endl;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	int t=1;	cin >> t;
	FOR(t) {
		//cout << "Case #" <<  (i+1) << ": ";
		solve();
	}


#ifdef LOCAL_DEFINE
	cerr << endl << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s" << endl;
#endif
	return 0;
}