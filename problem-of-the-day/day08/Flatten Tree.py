# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
      
    def flatten(self, root: TreeNode) -> None:
        """
        Input: root node of binary tree
        Output: convert binary tree to right-skewed linked list
        """
        
        # record of node of previous traversal
        previous_traversal = None
        
        def helper( node):
        
            if node:

                # DFS travesal to next level
                
                helper( node.right )
                helper( node.left )

                # flattern binary tree to right skewed linked list
                
                nonlocal previous_traversal
                node.right = previous_traversal
                node.left = None
                previous_traversal = node
                
        # ---------------------
        
        helper(root)