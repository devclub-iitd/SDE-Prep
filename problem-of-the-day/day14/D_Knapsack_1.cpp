#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Time Complexity: O(n*w)

int main()
{
    ll n , w ;
    cin>>n>>w;
    vector<ll>weight(n) , value(n);
    for(int i = 0 ; i<n ; i++)
    {
        cin>>weight[i]>>value[i];
    }
    vector<vector<ll>>dp(n+1 , vector<ll>(w+1 , 0));
    for(int i = 1 ; i<=n ; i++)
    {
        for(int j = 1 ; j<=w ; j++)
        {
            if(weight[i-1] <= j)
            {
                dp[i][j] = max(dp[i][j] , value[i-1] + dp[i-1][j-weight[i-1]]);
            }
            dp[i][j] = max(dp[i][j] , dp[i-1][j]);
        }
    }
    cout<<dp[n][w]<<endl;
}