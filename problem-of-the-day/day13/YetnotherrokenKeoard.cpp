#include<iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)


void solve() {
    string s;cin>>s;
    int n = s.size();
    vector<bool>a(n,true);
    int B=0,b=0;
    char c;
    for(int i = n-1; i>=0 ;i--){
        c = s[i];
        if(c=='b'){
            a[i]=false;
            b++;
        }
        else if(c=='B'){
            a[i]=false;
            B++;
        }
        else{
            if('a'<=c && c<='z' && b>0){
                a[i]=false;
                b--;
            }
            else if('A'<=c && c<='Z' && B>0){
                a[i]=false;
                B--;
            }
        }
    }
    rep(i,0,n){
        if(a[i])cout<<s[i];
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