class Solution {
public:
    void reverse(int i, int j, vector<int>&nums){
        if(i>=j)return;
        while(i<j){
            swap(nums[i],nums[j]);
            i++;
            j--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        reverse(0,n-1,nums);
        reverse(0,k-1,nums);
        reverse(k,n-1,nums);
    }
};