/// inbuilt function to perform this operation is equal_range() which returns a pair of iterators pointing to the first element and last element of the range of elements that are equal to the value passed as argument.
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int index1 = -1, index2 = -1;
        int n = nums.size();
        int start = 0, end = n-1, mid;
        mid = start + (end-start)/2;

        //finding first occurance
        while(start <= end){
            if(target == nums[mid]){
                index1 = mid;
                end = mid-1;
            }
            else if(target < nums[mid]){
                end = mid-1;
            }
            else start = mid+1;
            mid = start + (end-start)/2;
        }

        start = 0; end = n-1; mid = start + (end-start)/2;

        //finding last occurance 
        while(start <= end){
            if(target == nums[mid]){
                index2 = mid;
                start = mid+1;
            }
            else if(target < nums[mid]){
                end = mid-1;
            }
            else start = mid+1;
            mid = start + (end-start)/2;
        }

        ans.push_back(index1);
        ans.push_back(index2);
        return ans;
    }
};

