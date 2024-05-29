class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, h = nums.size() - 1; // Initialize 'l' to the start and 'h' to the end of the vector
        int m; // Declare a variable 'm' to store the middle index
        // Loop while the search space is valid (l <= h)
        while (l <= h) {
            m = l + (h - l) / 2; // Calculate the middle index to avoid potential overflow            
            // If the middle element is the target, return the index 'm'
            if (nums[m] == target) return m;
            // If the middle element is greater than the target, discard the right half
            else if (nums[m] > target) h = m - 1;
            // If the middle element is less than the target, discard the left half
            else l = m + 1;
        }
        // If the target is not found, return -1
        return -1;
    }
};
