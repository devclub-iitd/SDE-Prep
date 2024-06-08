class Solution {
public:
    void flatten(TreeNode* root) {
        
        // record of node of previous traversal
        TreeNode* prev = nullptr;
        
        std::function< void(TreeNode*) > helper;
        helper = [&](TreeNode* node) -> void {
            
            if( node != nullptr ){
                
                // DFS travesal to next level
                helper( node->right );
                helper( node->left );
                
                // flattern binary tree to right skewed linked list
                node->right = prev;
                node->left = nullptr;
                prev = node;
            }
            return;
        };
        
        // ----------------------
        helper( root );
        
        return;
    }
};