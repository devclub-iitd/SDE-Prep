#include <iostream>
#include<vector>
using namespace std;
#define pb push_back
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)

void dep(vector<int>adj[],vector<int>&depth,int node, int par) {
    for(auto i:adj[node]) {
        if(i == par)continue;
        dep(adj,depth,i,node);
        depth[node] = max(depth[node], 1 + depth[i]);
    }
}
 
void dia(vector<int>adj[], vector<int>&depth, vector<int>&diameter, int node, int par) {
    int m1 = 0, m2 = 0;
    for(auto i:adj[node]) {
        if(i == par)continue;
        dia(adj,depth,diameter,i,node);
        diameter[node] = max(diameter[node], diameter[i]);
        if(depth[i] >= m1) {
            m2 = m1;
            m1 = depth[i];
        } else if(depth[i] > m2) {
            m2 = depth[i];
        }
    }
    diameter[node] = max(diameter[node], m1 + m2 + 1);
}
int32_t main() {
    int n;cin>>n;
    vector<int>adj[n+1];
    int u,v;
    vector<int>diameter(n+1, 0);
    vector<int>depth(n+1,1);
    rep(i, 0, n-1) {
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dep(adj,depth,1,0);
    dia(adj,depth,diameter,1,0);
    // show(depth);
    // show(diameter);
    cout<<diameter[1]-1<<endl;
  return 0;
}
