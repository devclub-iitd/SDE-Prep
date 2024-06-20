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
  ll n,k;cin>>n>>k;
  vector<vector<ll>>adj(n+1);
  ll a,b;
  rep(i,0,n-1){
    cin>>a>>b;
    adj[a].push_back(b);adj[b].push_back(a);
  }
  function<bool(ll)>check = [&](ll x){
    vector<ll>sz(n+1,1ll);
    ll components = 0;
    // debug(x);
    function<void(ll,ll)>dfs = [&](ll at, ll par){
      for(ll to:adj[at]){
        if(to==par)continue;
        dfs(to,at);
        if(sz[to]>=x){
          // cout<<"Cuts "<<at<<" "<<to<<'\n';
        }
        else sz[at]+=sz[to];
      }
      if(sz[at]>=x)components++;
    };
    dfs(1,0);
    return (components>k);
  };
  ll low = 0, high = n;
  ll mid = 0 , ans = 0;
  while(low<=high){
    mid = low + (high - low)/2;
    if(check(mid)){
      ans = mid;
      low = mid + 1;
    }
    else{
      high = mid - 1;
    }
  }
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