def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
    if not preorder:
        return None
    root=TreeNode(preorder[0])
    mid=inorder.index(root.val)
    root.left=self.buildTree(preorder[1:mid+1],inorder[:mid])
    root.right=self.buildTree(preorder[mid+1:],inorder[mid+1:])
    return root