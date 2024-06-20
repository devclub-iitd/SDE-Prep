#include <algorithm>
#include <bitset>
#include <deque>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <stdlib.h>
#include <unordered_set>
#include <vector>
#include<functional>
/// ordered sets support upperbound lowerbound too
#include <map>
#include <unordered_map>
#include <cstring>
#define len(v) (int)v.size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
#define pb push_back
#define rep(i, a, b) for (int i = a; i < b; i++)
#define f first
#define mk make_pair
#define in insert
#define py cout << "YES\n"
#define pn cout << "NO\n"
#define fill(v,a,b) rep(i,a,b)cin>>v[i]
template <typename T> void chkmin(T &x, T y) {
  if (x > y)
    x = y;
}
template <typename T> void chkmax(T &x, T y) {
  if (x < y)
    x = y;
}

#ifndef ONLINE_JUDGE
#define debug(x) cout << #x << " = " << x << endl
#define show1(v)                                                               \
  for (auto i : v)                                                             \
  cout << i << ' '
#define show(v)                                                                \
  show1(v);                                                                    \
  cout << '\n'
#define __gcd __algo_gcd
#else
#define debug(x)
#endif
const ll INF = 1e9;
const ll LINF = INF * INF;

// ------------------------------------------***--------------------------------------------------



void solve() {
    ll n,m,k,d;cin>>n>>m>>k>>d;
    vector<ll>cost(n);
    rep(r,0,n){
        vector<ll>row(m);
        rep(i,0,m)cin>>row[i];
        vector<ll>dp(m);
        dp[0]=1;
        multiset<ll>ms={1};
        rep(i,1,m){ 
            dp[i] = 1 + row[i] + *ms.begin();
            ll idxremove = i - 1 - d;
            if(idxremove>=0){
                ms.erase(ms.find(dp[idxremove]));
            }
            ms.insert(dp[i]);
        }
        cost[r] = dp[m-1];
    }
    rep(i,1,n)cost[i]+=cost[i-1];
    ll ans = cost[k-1];
    rep(i,k,n)ans = min(ans,cost[i]-cost[i-k]);
    cout<<ans<<'\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
      solve();
    }
    return 0;
}