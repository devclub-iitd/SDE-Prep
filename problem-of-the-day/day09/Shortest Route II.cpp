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
void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> dist(n, vector<int>(n, LINF));
    rep(i, 0, m) {
        int u, v, c;
        cin >> u >> v >> c;
        --u, --v;
        dist[u][v] = min(dist[u][v], c);
        dist[v][u] = min(dist[v][u], c);
    }
    rep(i, 0, n) dist[i][i] = 0;
    rep(k, 0 ,n) {
        rep(i, 0 , n) {
            rep(j, 0 , n) {
                // if (dist[i][k] < LINF && dist[k][j] < LINF) { //when negative
                // weight edges exist
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                //}
            }
        }
    }
    while (q--) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        cout << (dist[u][v] == LINF ? -1 : dist[u][v]) << "\n";
    }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
