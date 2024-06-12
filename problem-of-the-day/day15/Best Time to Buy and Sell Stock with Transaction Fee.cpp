class Solution {
public:
long long dp[100002][2];
    long long solve (vector<int>& nums,int i,int flag,int k)
    {
        if(i>=nums.size())return 0;
        long long take=0;
        if(dp[i][flag]!=-1)return dp[i][flag];
        if(flag==0)
        {
            take+= max(nums[i]+f(nums,i+1,1,k),f(nums,i+1,flag,k));
        }
        if(flag==1)
        {
            take+= max(-nums[i]-k+f(nums,i+1,0,k),f(nums,i+1,flag,k));
            //deductiong concession fee k
        }
        return  dp[i][flag] =  take;
        
    }
    int maxProfit(vector<int>& nums, int fee) {
        memset(dp,-1,sizeof(dp));
        return f(nums,0,1,fee);
        
    }
};