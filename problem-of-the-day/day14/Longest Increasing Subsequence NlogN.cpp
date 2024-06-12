class Solution {
public:
    // Time Complexity: O(nlogn)
    // Space Complexity: O(n)
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size() ;
        vector<int>lis;
        lis.push_back(nums[0]);
        for(int i = 0 ; i<n ; i++)
        {
            if(lis.back() < nums[i])
            {
                lis.push_back(nums[i]);
            }
            else
            {
                int ind = lower_bound(lis.begin() , lis.end() , nums[i]) - lis.begin() ;
                if(lis[ind] != nums[i])
                {
                    lis[ind] = nums[i];
                }
            }
        }
        return lis.size();
    }
};