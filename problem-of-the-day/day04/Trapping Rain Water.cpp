class Solution {
public:
    // We will use two arrays left and right to store the maximum height of the building to the left and right of the current building
    // The amount of water that can be trapped at a building is min(left[i],right[i]) - height[i]
    // We will calculate the left and right arrays and then calculate the amount of water that can be trapped at each building
    // and then will sum the amount of water that can be trapped at each building to get the total amount of water that can be trapped

    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>left(n);
        vector<int>right(n);
        left[0] = height[0];
        right[n-1] = height[n-1];
        for(int i = 1 ; i<n ; i++)
        {
            left[i] = max(left[i-1] , height[i]);
        }
        for(int i = n-2 ; i>=0 ; i--)
        {
            right[i] = max(right[i+1] , height[i]);
        }

        int ans = 0 ;
        for(int i = 0 ; i<n ; i++)
        {
            ans += min(left[i],right[i]) - height[i];
        }
        return ans;
    }
};