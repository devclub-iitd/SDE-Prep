#include<iostream>
#define int long long
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;cin>>n;
  vector<vector<int>>a(n,vector<int>(n));  
  rep(i,0,n){
    rep(j,0,n)cin>>a[i][j];
  }
  int mn = a[0][n-1];
  rep(i,0,n){
    mn = min(mn,a[i][n-1-i]);
  }
  int sum = 0ll;
  rep(i,0,n)sum = accumulate(all(a[i]),sum);
  cout<<sum-mn<<endl;
  return 0;
}