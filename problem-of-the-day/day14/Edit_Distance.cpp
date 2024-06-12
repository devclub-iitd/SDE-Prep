#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main()
{
    string a,b ;
    cin>>a>>b;
    ll s1 = a.size() ;
    ll s2 = b.size() ;
    vector<vector<ll>>dp(s1 + 1 , vector<ll>(s2 + 1 , INT_MAX)) ; 
    for(int i = 0 ; i<=s1 ; i++)
    {
        dp[i][0] = i;
    }
    for(int i = 0 ; i<=s2 ; i++)
    {
        dp[0][i] = i;
    }
    for(int i = 1 ; i<=s1 ; i++)
    {
        for(int j = 1 ; j<=s2 ; j++)
        {
            dp[i][j] = min(dp[i][j],1 + dp[i-1][j]);
            dp[i][j] = min(dp[i][j],1 + dp[i][j-1]);
            dp[i][j] = min(dp[i][j] , (a[i-1]!=b[j-1]) + dp[i-1][j-1]);
        }
    }
    // for(auto x : dp)
    // {
    //     for(auto y : x)
    //     {
    //         cout<<y<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<dp[s1][s2]<<endl;

}