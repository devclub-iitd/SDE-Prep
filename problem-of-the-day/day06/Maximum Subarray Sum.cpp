class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int curr = nums[0], ans = curr;
        for(int i = 1 ; i < n ; i++){
            curr = max(nums[i], nums[i] + curr);
            ans = max(ans,curr);
        }
        return ans;
    }
};