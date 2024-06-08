class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>> levelOrder(TreeNode* root) {
        ans = vector<vector<int>>();
        if(!root)return ans;
        queue<TreeNode*>stk1;
        stk1.push(root);
        queue<TreeNode*>stk2;
        TreeNode*n;
        vector<int>temp;
        while(!stk1.empty()){
            temp.clear();
            stk2 = queue<TreeNode*>();
            while(!stk1.empty()){
                n = stk1.front();
                stk1.pop();
                temp.push_back(n->val);
                if(n->left)stk2.push(n->left);
                if(n->right)stk2.push(n->right);
            }
            ans.push_back(temp);
            stk1 = stk2;
        }
        return ans;
    }
};