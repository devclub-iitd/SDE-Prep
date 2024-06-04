#include <algorithm>
#include <unordered_set>
#include <vector>
#include<iostream>
#define len(v) (int)v.size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
#define int long long
#define pb push_back
#define rep(i, a, b) for (int i = a; i < b; i++)




// ------------------------------------------***--------------------------------------------------

void help(int i, string&s, vector<int>&ans,vector<vector<int>>&a){
    // debug(i);
    if(i==0){
        return;
    }
    if(a[i][0]==0 && a[i][1]==0){
        ans[i] = 0;
        return;
    }
    help(a[i][0],s,ans,a);
    help(a[i][1],s,ans,a);
    int left = ans[a[i][0]];
    int right = ans[a[i][1]];
    if(left < right){
        if(s[i]=='L')ans[i] = left;
        else{
            s[i]='R';
            ans[i] = 1 + left;
        }
    }
    else if(left > right){
        if(s[i]=='R')ans[i] = right;
        else{
            s[i]='L';
            ans[i] = 1 + right;
        }
    }
    else{
        if(s[i]=='U')ans[i] = 1 + right;
        else{
            s[i]='L';
            ans[i] = left;
        }
    }
}

void solve() {
    int n;cin>>n;
    string s;cin>>s;
    vector<vector<int>>a(n+1,vector<int>(2,0));
    rep(i,1,n+1)cin>>a[i][0]>>a[i][1];
    s = " " + s;
    vector<int>ans(n+1,n+2);
    ans[0] = n+2;
    help(1,s,ans,a);
    // show(ans);
    cout<<ans[1]<<'\n';
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