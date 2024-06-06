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

#include<cassert>

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
  vector<vector<int>>ans;
  vector<int>low(n+1),ids(n+1);
  stack<int>stk;
  vector<bool>onStack(n+1,false);
  int id = 0;
  vector<bool>vis(n+1,false);
  function<void(int)>scc = [&](int at){
    id++;
    vis[at]=true;
    ids[at] = low[at] = id;
    stk.push(at);
    onStack[at] = true;
    for(int to:adj[at]){
        if(ids[to]==0)scc(to);
        if(onStack[to])low[at] = min(low[at],low[to]);
    }
    if(ids[at]==low[at]){
        vector<int>curr;
        while(stk.top() != at){
            int node = stk.top();
            stk.pop();
            onStack[node]=false;
            low[node] = ids[at];
            curr.pb(node);
        }
        assert(stk.top() == at);
        stk.pop();
        onStack[at] = false;
        curr.pb(at);
        ans.pb(curr);
    }
  };
  function<bool(int,int)>canReach=[&](int start,int end){
    vector<bool>vis(n+1,false);
    function<bool(int)>dfs = [&](int at){
        vis[at] = true;
        if(at == end)return true;
        for(int to:adj[at]){
            if(!vis[to] && dfs(to))return true;
        }
        return false;
    };
    return dfs(start);
  };
  for(int i = 1; i <= n ; i++){
    if(!vis[i])scc(i);
  }
  cout<<ans.size()<<'\n';
  vector<int>result(n+1);
  rep(i,0,ans.size()){
    for(int j:ans[i])result[j]=i+1;
  }
  rep(i,1,n+1)cout<<result[i]<<' ';
  return 0;
}
