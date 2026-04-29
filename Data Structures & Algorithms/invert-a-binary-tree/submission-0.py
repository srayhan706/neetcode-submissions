# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if not root:
            return None
        d=deque([root])

        while d:
            node=d.popleft()
            node.left,node.right=node.right,node.left
            if node.left:
                d.append(node.left)
            if node.right:
                d.append(node.right)

        return root
        