class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxPath = INT_MIN;  // Initialize maxPath to store the result
        DFS(root, maxPath);  // Call the DFS function
        return maxPath;  // Return the final maximum path sum
    }
private:
    int DFS(TreeNode* root, int& maxPath) {
        if (root == NULL) {
            return 0;  // Base case: return 0 if the node is NULL
        }
        
        // Recursive calculation for left and right subtrees
        // Ensure that negative values are not considered (max(DFS(...), 0))
        int lmax = max(DFS(root->left, maxPath), 0);
        int rmax = max(DFS(root->right, maxPath), 0);
        
        // Update the overall maximum path sum
        maxPath = max(maxPath, root->val + lmax + rmax);
        
        // Return the maximum path sum that starts from the current node
        return root->val + max(lmax, rmax);
    }
};