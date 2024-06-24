#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define f(i, a, b) for (int i = a; i <= b; i++)
#define ff(i, a, b) for (int i = a; i >= b; i--)
#define mod 1000000007
 
 
void solve(){
   ll a,b;
   cin>>a>>b;
   ll ans = b-a;
   f(i,a,b){
      ll as = 0;
      f(j,0,63){
        if(i&(1LL<<j)){
            if(b&(1LL<<j)){}
            else {
                as+= (1LL<<j);
            }
        }
      }
      ans = min(ans,as + i-a+1);
   }
 
   f(i,b,b+a+1){
      ll as = 0;
      f(j,0,63){
        if(a&(1LL<<j)){
            if(i&(1LL<<j)){}
            else {
                as+= (1LL<<j);
            }
        }
      }
      ans = min(ans,as + i-b+1);
   }
 
   cout<<ans<<endl;
 
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}