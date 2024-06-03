#include<iostream>
#define int long long
using namespace std;

void solve() {
    int n;cin>>n;
    int start = n/2 + 1;
    for(int i = start ; i <=n ; i++){
        cout<<i<<' ';
        if(i-start+1<start)cout<<i-start+1<<' ';
    }
    cout<<'\n';
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