/*The main idea is DP. Let's define dp[x] as the maximal value of the length of the good sequence whose last element is x, 
and define d[i] as the (maximal value of dp[x] where x is divisible by i).

You should calculate dp[x] in the increasing order of x.
The value of dp[x] is (maximal value of d[i] where i is a divisor of x) + 1. 
After you calculate dp[x], for each divisor i of x, you should update d[i] too.

This algorithm works in O(nlogn) because the sum of the number of the divisor from 1 to n is O(nlogn).

Note that there is a corner case. When the set is {1}, you should output 1.
*/


#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define vl vector<ll>
#define pb push_back
#define pop pop_back
#define vi vector<int>
#define vb vector<bool>
#define rep(i,n) for (ll i = 0; i < (ll)(n); i++)
#define all(v) v.begin(), v.end()

vl divisor(ll n){
    vl div(0);
    set<ll> s;
    for (ll i = 2; i * i <= n ; i++)
    {
        if(s.find(i) != s.end()){
            break;
        }
        if(n % i == 0){
            s.insert(i);
            s.insert(n / i);
            div.pb(i);
            div.pb(n / i);
        }
    }
    div.pb(n);
    return div;
}
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    ll n;
    cin>>n;
    vl a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    if(n == 1){
        cout<<1<<endl;
    }else{
        vl dp(n);
        vl d(a[n - 1] + 1);
        for(int i = 0; i < n; i++){
            vl div = divisor(a[i]);
            ll maxi = 0; 
            for (auto it : div)
            {
                maxi = max(d[it], maxi);
            }
            dp[i] = max(dp[i], maxi + 1);
            for (auto it : div)
            {
                d[it] = dp[i];
            }
        }
        cout<<*max_element(all(dp))<<endl;
    }
}
