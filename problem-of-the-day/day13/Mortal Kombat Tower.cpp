#include<iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)

void solve() {
    int n;cin>>n;
    vector<int>a(n+1);
    rep(i,1,n+1)cin>>a[i];
    vector<int>f(n+2,0);
    vector<int>m(n+2,0);
    if(a[n]==1)f[n]=1;
    for(int i = n-1 ; i>=1 ; i--){
        f[i] = min( m[i+2] + a[i] + a[i+1],m[i+1] + a[i]);
        m[i] = min(f[i+1],f[i+2]);
    }
    cout<<f[1]<<'\n';
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