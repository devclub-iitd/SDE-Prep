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
// ------------------------------------------***--------------------------------------------------





int32_t main() {
    int n,q;cin>>n>>q;
    vector<int>a(n+1,0);
    int x;
    rep(i,1,n+1){
        cin>>x;
        a[i]=a[i-1]+x;
    }
    int l,r;
    while(q--){
        cin>>l>>r;
        cout<<a[r]-a[l-1]<<'\n';
    }
  return 0;
}
