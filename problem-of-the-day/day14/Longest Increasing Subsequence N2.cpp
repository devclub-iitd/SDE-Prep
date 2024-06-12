class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n =  nums.size();
        vector<int>dp(n,1);
        // dp[i] stores the length of longest increasing subsequence ending at i
        for(int i = 1 ; i<n ; i++)
        {
            for(int j = i-1 ; j>=0 ; j--)
            {
                if(nums[i]>nums[j])
                {
                    dp[i] = max(dp[i] , 1 + dp[j]);
                }
            }
        }
        return *max_element(dp.begin() , dp.end());
    }
};