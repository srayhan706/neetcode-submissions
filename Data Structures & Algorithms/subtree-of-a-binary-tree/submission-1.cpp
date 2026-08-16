/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool issametree(TreeNode* p,TreeNode* q){
        if(!p && !q){
            return true;
        }

        if(!p || !q){
            return false;
        }

        return p->val==q->val && issametree(p->left,q->left) && issametree(p->right,q->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        if(!subRoot){
            return true;
        }

        if(!root){
            return false;
        }



        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot) || issametree(root,subRoot);
        
    }
};
