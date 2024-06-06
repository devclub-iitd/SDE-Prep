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
const int INF = 1e9;
const int LINF = INF * INF;

// ------------------------------------------***--------------------------------------------------

struct  Edge{
    int from; int to;
    int weight;
    Edge(int from, int to, int weight):from(from), to(to), weight(weight){
    }
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
    bool operator>(const Edge& other) const {
        return weight > other.weight;
    }
};

struct Graph{
    int n;
    vector<vector<Edge>> adj;
    vector<Edge> edges;
    bool directed;
    Graph(int n, bool directed):n(n),directed(directed){
        adj.resize(n+1);
    }
    void addEdge(int from, int to, int weight){
        Edge e1(from, to, weight);
        adj[from].push_back(e1);
        edges.push_back(e1);
        if(!directed){
            Edge e2(to, from, weight);
            adj[to].push_back(e2);
            edges.push_back(e2);
        }
    }
};

/// O(V+E)
vector<vector<int>> scc(Graph G){
    int n = G.n;
    vector<int>ids(n+1,-1);
    vector<int>lowlink(n+1,-1);
    vector<bool>onstack(n+1,false);
    vector<vector<int>>ans;
    vector<vector<Edge>>adj = G.adj;
    int id = 0;
    stack<int>stk;
    vector<bool>vis(n+1,false);
    function<void(int)>sccdfs = [&](int at){
        id++;
        lowlink[at] = id;
        ids[at] = id;
        onstack[at] = true;
        stk.push(at);
        vis[at] = true;
        for(Edge e:adj[at]){
           if(ids[e.to]==-1)sccdfs(e.to);
           if(onstack[e.to])lowlink[at] = min(lowlink[at],lowlink[e.to]);
        }
        if(ids[at]==lowlink[at]){
            vector<int>curr;
            while(stk.top() != at){
                int node = stk.top();
                stk.pop();
                onstack[node] = false;
                lowlink[node] = ids[at];
                curr.push_back(node);
            }
            stk.pop();
            onstack[at] = false;
            curr.push_back(at);
            ans.push_back(curr);
        }
    };
    for(int i = 0; i <= n ; i++){
        if(!vis[i])sccdfs(i);
    }
    return ans;
}

/// O(V+E)
vector<int> toposort(Graph G){
    int n = G.n;
    vector<vector<Edge>>adj = G.adj;
    vector<int>indegree(n+1,0);
    for(int i = 0; i <= n; i++){
        for(Edge e:adj[i]){
            indegree[e.to]++;
        }
    }
    queue<int>q;
    vector<int>par(n+1);
    for(int i = 0; i <= n; i++){
        if(indegree[i]==0)q.push(i),par[i] = -1;
    }
    vector<int>ans;
    while(!q.empty()){
        int at = q.front();
        q.pop();
        ans.push_back(at);
        for(Edge e:adj[at]){
            indegree[e.to]--;
            if(indegree[e.to]==0)q.push(e.to),par[e.to]=at;
        }
    }
    return ans;
}

/// O(V + ElogV)
vector<int> shortestPathSingleSource(Graph G, int start){
    int n = G.n;
    vector<vector<Edge>>adj = G.adj;
    vector<int>dist(n+1,INF);
    dist[start] = 0;
    priority_queue<Edge,vector<Edge>,greater<Edge>>pq;
    pq.push(Edge(-1,start,0));
    while(!pq.empty()){
        Edge e = pq.top();
        pq.pop();
        for(Edge edge:adj[e.to]){
            if(dist[edge.to]>dist[e.to]+edge.weight){
                dist[edge.to] = dist[e.to]+edge.weight;
                pq.push(Edge(e.to,edge.to,dist[edge.to]));
            }
        }
    }
    return dist;
}

/// O(V^3)
vector<vector<int>> shortestPathAllPairs(Graph G){
    int n = G.n;
    vector<vector<Edge>>adj = G.adj;
    vector<vector<int>>dist(n+1,vector<int>(n+1,INF));
    for(int i = 0; i <= n; i++){
        dist[i][i] = 0;
    }
    for(int i = 0; i <= n; i++){
        for(Edge e:adj[i]){
            dist[e.from][e.to] = e.weight;
        }
    }
    for(int k = 0; k <= n; k++){
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= n; j++){
                if(dist[i][k]<INF && dist[k][j]<INF){
                    dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
    }
    return dist;
}

/// O(ElogE)
class UF {
public:
  int *id, cnt, *sz;
  // Create an empty union find data structure with N isolated sets.
  UF(int N) {
    cnt = N; id = new int[N]; sz = new int[N];
    for (int i = 0; i<N; i++)  id[i] = i, sz[i] = 1; }
  ~UF() { delete[] id; delete[] sz; }
  // Return the id of component corresponding to object p.
  int find(int p) {
    int root = p;
    while (root != id[root])    root = id[root];
    while (p != root) { int newp = id[p]; id[p] = root; p = newp; }
    return root;
  }
  // Replace sets containing x and y with their union.
  void merge(int x, int y) {
    int i = find(x); int j = find(y); if (i == j) return;
    // make smaller root point to larger one
    if (sz[i] < sz[j]) { id[i] = j, sz[j] += sz[i]; }
    else { id[j] = i, sz[i] += sz[j]; }
    cnt--;
  }
  // Are objects x and y in the same set?
  bool connected(int x, int y) { return find(x) == find(y); }
  // Return the number of disjoint sets.
    int count() { return cnt; }
};
int mst(Graph G){
    int n = G.n;
    vector<Edge>edges = G.edges;
    vector<bool>vis(n+1,false);
    vector<Edge>ans;
    priority_queue<Edge,vector<Edge>,greater<Edge>>pq(all(edges));
    UF uf(n+1);
    int mincost = 0;
    while(!pq.empty()){
        Edge e = pq.top();
        pq.pop();
        if(!uf.connected(e.from,e.to)){
            uf.merge(e.from,e.to);
            ans.push_back(e);
            mincost+=e.weight;
        }
    }
    if(ans.size()!=n-1)return -1;
    return mincost;
}



int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,m;cin>>n>>m;
  Graph G(n,false);
  rep(i,0,m){
    int u,v,c;cin>>u>>v>>c;
    G.addEdge(u,v,c);
 }
 int ans = mst(G);
 if(ans!=-1)cout<<ans;
 else cout<<"IMPOSSIBLE";
  return 0;
}
