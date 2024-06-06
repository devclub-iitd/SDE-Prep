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
  vector<vector<int>>adj(n+1);
  int a,b;
  rep(i,0,m){
    cin>>a>>b;
    adj[a].pb(b);

  }
  vector<int>ans;
  function<bool()>toposort = [&](){
      vector<int>indegree(n+1,0);
      vector<bool>vis(n+1,false);
      for(vector<int>&v:adj){
        for(int i:v)indegree[i]++;
      }
      queue<int>q;
      rep(i,1,n+1){
        if(indegree[i]==0)q.push(i);
      }
      while(!q.empty()){
        int at = q.front();
        q.pop();
        for(int j: adj[at]){
            indegree[j]--;
            if(indegree[j]==0)q.push(j);
        }
        ans.pb(at);
        vis[at]=true;
      }
      return (count(all(vis),true)==n);
  };
  if(toposort()){
      for(int i:ans)cout<<i<<' ';
  }
  else cout<<"IMPOSSIBLE";
  return 0;
}
