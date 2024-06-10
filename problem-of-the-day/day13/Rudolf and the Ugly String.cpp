#include<iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)

///DP solution
void solve() {
    int n;string s;cin>>n>>s;
    int i = n-2;
    vector<int>ans(n+1,0);
    for(int i = n-2; i>=0;i--){
        if(s.substr(i,3)=="map" || s.substr(i,3)=="pie"){
            ans[i] = 1ll + min(ans[i+1],min(ans[i+2],ans[i+3]));
        }
        else ans[i] = ans[i+1];
    }
    cout<<ans[0]<<'\n';
}

/// greedy
void solve(){
    int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> va;                 
	for (string sul : {"mapie", "pie", "map"}) {
		for (int pos = 0; (pos = s.find(sul, pos)) != string::npos;) {
			s[pos + sul.length() / 2] = '?';
			va.push_back(pos + sul.length() / 2);
		}
	}
	cout << va.size() << endl;
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