#include<iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)


void solve() {
    int n;string s;cin>>n>>s;
    int ans = 0;
    vector<bool>a(n+1,false),b(n+1,false);
    b[n-1] = (s[n-1]=='B');
    a[0] = (s[0]=='A');
    for(int i = n-2;i>=0;i--){
        b[i] = (s[i]=='B') || (b[i+1]);
    }
    rep(i,1,n){
        a[i] = (s[i] == 'A') || (a[i-1]);
    }
    rep(i,0,n-1){
        ans += a[i] && b[i+1];
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