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
#define py cout << "YES" << endl
#define pn cout << "NO" << endl
template <int MOD=998244353>
struct Modular {
  int value;
  static const int MOD_value = MOD;

  Modular(long long v = 0) { value = v % MOD; if (value < 0) value += MOD;}
  Modular(long long a, long long b) : value(0){ *this += a; *this /= b;}

  Modular& operator+=(Modular const& b) {value += b.value; if (value >= MOD) value -= MOD; return *this;}
  Modular& operator-=(Modular const& b) {value -= b.value; if (value < 0) value += MOD;return *this;}
  Modular& operator*=(Modular const& b) {value = (long long)value * b.value % MOD;return *this;}

  friend Modular mexp(Modular a, long long e) {
    Modular res = 1; while (e) { if (e&1) res *= a; a *= a; e >>= 1; }
    return res;
  }
  friend Modular inverse(Modular a) { return mexp(a, MOD - 2); }

  Modular& operator/=(Modular const& b) { return *this *= inverse(b); }
  friend Modular operator+(Modular a, Modular const b) { return a += b; }
  friend Modular operator-(Modular a, Modular const b) { return a -= b; }
  friend Modular operator-(Modular const a) { return 0 - a; }
  friend Modular operator*(Modular a, Modular const b) { return a *= b; }
  friend Modular operator/(Modular a, Modular const b) { return a /= b; }
  friend std::ostream& operator<<(std::ostream& os, Modular const& a) {return os << a.value;}
  friend bool operator==(Modular const& a, Modular const& b) {return a.value == b.value;}
  friend bool operator!=(Modular const& a, Modular const& b) {return a.value != b.value;}
};
template <typename T> void chkmin(T &x, T y) {
  if (x > y)
    x = y;
}
template <typename T> void chkmax(T &x, T y) {
  if (x < y)
    x = y;
}

void sigsev(int n, vector<int> &prime) {
    prime.push_back(2);
    vector<bool>ispm(n + 1, true);

    for(int j = 3; j <= n; j += 2) {
      if(!ispm[j])continue;
      else{
        prime.push_back(j);
        for(int i = j*j; i <= n; i += j) {
          ispm[i] = false;
        }
      }
    }
}

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

class SG {
public:
    vector<int>data;
    int n;
    vector<int>tree;
    function<int(int, int)> operation;
    int default_val;
    SG(vector<int>&data , int default_val , function<int(int, int)> op):operation(op) {
        this->data = data;
        n = data.size();
        this->default_val = default_val;
        tree.resize(4*n);
        build(0, n-1, 1);
    }
    void build(int l, int r, int node) {
        if(l == r) {
            tree[node] = data[l];
            // cout<<l<<" "<<r<<" "<<tree[node]<<endl;
            return;
        }
        int mid = (l+r)/2;
        build(l, mid, 2*node);
        build(mid+1, r, 2*node+1);
        tree[node] = operation(tree[2*node], tree[2*node+1]);
        // cout<<l<<" "<<r<<" "<<tree[node]<<endl;
    }
    int query(int v, int tl, int tr, int l , int r){
        if (l > r) return default_val;
        else if (l == tl && r == tr) {
            return tree[v];
        }
        int tm = (tl + tr) / 2;
        return operation(query(v*2, tl, tm, l, min(r, tm)),query(v*2+1, tm+1, tr, max(l, tm+1), r));
    }
    int query(int ql, int qr) {
        return query(1, 0, n-1, ql, qr);
    }
    void update(int v, int tl, int tr, int l, int r, int new_val) {
        if (l > r)
            return;
        if (l == tl && r == tr) {
            tree[v] = new_val;
        } else {
            int tm = (tl + tr) / 2;
            update(v*2, tl, tm, l, min(r, tm), new_val);
            update(v*2+1, tm+1, tr, max(l, tm+1), r, new_val);
        }
    }
    void update(int l, int r, int new_val){
        update(1, 0, n-1, l, r, new_val);
    }
};


#ifndef ONLINE_JUDGE
#define debug(x) cout << #x << " = " << x << endl
#define show1(v)                                                               \
  for (auto i : v)                                                             \
  cout << i << ' '
#define show(v)                                                                \
  show1(v);                                                                    \
  cout << '\n'
#define gcd __algo_gcd
#else
#define debug(x)
#endif


// ------------------------------------------***--------------------------------------------------





int32_t main() {
    int n,q;
    cin>>n>>q;
    vector<int>data(n,0);
    rep(i,0,n)cin>>data[i];
    SG s(data, INT32_MAX ,[](int a, int b) { return min(a,b); }); // Using lambda function
    int l,r;
    while(q--){
        cin>>l>>r;
        cout<<s.query(l-1,r-1)<<endl;
    }   
  return 0;
}
