class Solution {
public:
    int isPossible(vector<int>& nums, int k, int mid){
        int PageSum = 0;
        int count = 1;
        for (int i = 0 ; i < nums.size(); i++){
            if ((PageSum + nums[i]) <= mid){
                PageSum += nums[i];
            }
            else{
                count++;
                if (count > k || nums[i] > mid){
                    return false;
                }
                PageSum = nums[i];
            }
        }
        return true;
    }
    
    int splitArray(vector<int>& nums, int k) {
        int sum = 0;
        int ans = -1;
        for (int i = 0 ; i < nums.size() ; i++){
            sum += nums[i];
        }
        int start = 0;
        int end = sum;
        while (start <= end){
            int mid = start + (end - start) / 2;
            if (isPossible(nums, k, mid)){
                ans = mid;
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return ans;
    }
};