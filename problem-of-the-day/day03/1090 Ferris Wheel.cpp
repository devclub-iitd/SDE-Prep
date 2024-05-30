#include<bitset>
#include<vector>
#include <iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<deque>
#include<unordered_set>
#include<set>
///ordered sets support upperbound lowerbound too
#include<map>
#include<unordered_map>
using namespace std;
#define int long long
#define pb push_back
#define rep(i,a,b) for(int i=a;i<b;i++)
#define f first
#define mk make_pair
#define in insert  
#define all(x) x.begin(),x.end()

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,x;cin>>n>>x;
  vector<int>a(n);
  rep(i,0,n)cin>>a[i];
  sort(all(a));
  int ans = 0;
  int i = 0, j = n-1;
  int sum = 0;
  while(i<j){
    sum = a[i] + a[j];
    if(sum<=x){
        ans++;
        i++;j--;
    }
    else{
        ans++;
        j--;
    }
  }
  if(i==j)ans++;
  cout<<ans;
  return 0;
}
