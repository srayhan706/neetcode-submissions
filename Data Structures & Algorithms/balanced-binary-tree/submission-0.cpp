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

    int height(TreeNode* node){
        if(node==nullptr){
            return -1;
        }

        return 1+max(height(node->left),height(node->right));
    }


    bool isBalanced(TreeNode* root) {
        bool ans=true;

        if(root==nullptr){
            return ans;
        }

        int lheight=height(root->left);
        int rheight=height(root->right);

        if (abs(lheight-rheight)>1){
            return false;
        }

        return isBalanced(root->left) && isBalanced(root->right);






        
    }
};
