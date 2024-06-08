class Solution(object):
    def kthSmallest(self, root, k):
        self.count = 0
        self.result = 0
        self.inorderTraversal(root, k)
        return self.result
    
    def inorderTraversal(self, node, k):
        if not node or self.count >= k:
            return
        
        self.inorderTraversal(node.left, k)
        
        self.count += 1
        if self.count == k:
            self.result = node.val
            return
        
        self.inorderTraversal(node.right, k)