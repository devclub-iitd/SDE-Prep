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
#define len(v) (int)v.size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
#define int long long
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


// ------------------------------------------***--------------------------------------------------


int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,m;cin>>n>>m;
  vector<vector<pair<int,int>>>adj(n+1);
  int a,b,c;
  rep(i,0,m){
    cin>>a>>b>>c;
    adj[a].pb({c,b});
  }
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
  pq.push({0,1});
  vector<int>dist(n+1,INT64_MAX);
  dist[1]=0;
  vector<bool>vis(n+1,false);
  while(!pq.empty()){
    auto [d,v] = pq.top();
    pq.pop();
    if(vis[v])continue;
    vis[v]=true;
    for(auto&[dis,u]:adj[v]){
        dist[u] = min(dist[u],dist[v]+dis);
        pq.push({dist[u],u});
    }
  }
  for(int i = 1 ; i <= n ; i++)cout<<dist[i]<<' ';
  return 0;
}
