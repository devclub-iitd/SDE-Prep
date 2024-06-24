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
    ll n;cin>>n;
    cout<<"? 0 0 1 1"<<endl;
    cout.flush();
    char c;cin>>c;
    ll best;
    if(c == '>')best = 0;
    else best = 1;
    rep(i,2,n){
        cout<<"? "<<i<<' '<<i<<' '<<best<<' '<<best<<endl;
        cout.flush();
        cin>>c;
        if(c =='>')best = i;
    }
    ll bestans = 64 - __builtin_clzll(n);
    bestans = (1<<bestans) - 1;
    ll best2;
    cout<<"? "<<best<<" 0 1 "<<best<<endl;
    cout.flush();
    vector<ll>possible;
    cin>>c;
    if(c=='>')possible.push_back(0);
    else if(c=='<')possible.push_back(1);
    else{
        possible.push_back(0);possible.push_back(1);
    }
    best2 = possible.back();
    rep(i,2,n){
        if(i==best)continue;
        cout<<"? "<<i<<" "<<best<<" "<<best2<<' '<<best<<endl;
        cout.flush();
        cin>>c;
        if(c=='>'){
            possible.clear();
            possible.push_back(i);
            best2 = i;
        }
        else if(c=='='){
            possible.push_back(i);
        }
    }
    ll mn = possible[0];
    rep(i,1,possible.size()){
        cout<<"? "<<mn<<" "<<mn<<" "<<possible[i]<<" "<<possible[i]<<endl;
        cout.flush();
        cin>>c;
        if(c=='>'){
            mn = possible[i];
        }
    }
    cout<<"! "<<best<<" "<<mn<<'\n';
    cout.flush();
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
}#include <algorithm>
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
    ll n;cin>>n;
    cout<<"? 0 0 1 1"<<endl;
    cout.flush();
    char c;cin>>c;
    ll best;
    if(c == '>')best = 0;
    else best = 1;
    rep(i,2,n){
        cout<<"? "<<i<<' '<<i<<' '<<best<<' '<<best<<endl;
        cout.flush();
        cin>>c;
        if(c =='>')best = i;
    }
    ll bestans = 64 - __builtin_clzll(n);
    bestans = (1<<bestans) - 1;
    ll best2;
    cout<<"? "<<best<<" 0 1 "<<best<<endl;
    cout.flush();
    vector<ll>possible;
    cin>>c;
    if(c=='>')possible.push_back(0);
    else if(c=='<')possible.push_back(1);
    else{
        possible.push_back(0);possible.push_back(1);
    }
    best2 = possible.back();
    rep(i,2,n){
        if(i==best)continue;
        cout<<"? "<<i<<" "<<best<<" "<<best2<<' '<<best<<endl;
        cout.flush();
        cin>>c;
        if(c=='>'){
            possible.clear();
            possible.push_back(i);
            best2 = i;
        }
        else if(c=='='){
            possible.push_back(i);
        }
    }
    ll mn = possible[0];
    rep(i,1,possible.size()){
        cout<<"? "<<mn<<" "<<mn<<" "<<possible[i]<<" "<<possible[i]<<endl;
        cout.flush();
        cin>>c;
        if(c=='>'){
            mn = possible[i];
        }
    }
    cout<<"! "<<best<<" "<<mn<<'\n';
    cout.flush();
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