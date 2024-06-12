    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long

    // Time Complexity: O(n*sum(v))
    // IN dp[i][j] , we store the minimum weight required to get value j using first i items

    int main()
    {
        ll n , w ;
        cin>>n>>w;
        vector<ll>weight(n) , value(n);
        for(int i = 0 ; i<n ; i++)
        {
            cin>>weight[i]>>value[i];
        }
        ll sum = 0;
        for(auto x : value)
        {
            sum+=x;
        }
        vector<vector<ll>>dp(n+1 , vector<ll>(sum+1 , INT_MAX));
        dp[0][0] = 0;
        for(int i = 1 ; i<=n ; i++)
        {
            for(int j = 0 ; j<=sum ; j++)
            {
                dp[i][j] = dp[i-1][j];
                if(j>=value[i-1])
                {
                    dp[i][j] = min(dp[i][j] , weight[i-1] + dp[i-1][j-value[i-1]]);
                }
            }
        }
        ll ans = 0;
        for(int i = 0 ; i<=sum ; i++)
        {
            if(dp[n][i]<=w)
            {
                ans = i;
            }
        }
        cout<<ans<<endl;
    }
