/************************
 * Balanced Binary Tree *
 ************************/

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
    int heightOfSubtree(TreeNode* root, bool& ans) {
        if(root == NULL || ans == false){
            return 0;
        }
        
        int leftSubHeight = heightOfSubtree(root -> left, ans);
        int rightSubHeight = heightOfSubtree(root -> right, ans);
        
        if(leftSubHeight - rightSubHeight < -1 || leftSubHeight - rightSubHeight > 1){
            ans = false;
        }
        
        return 1 + max(leftSubHeight, rightSubHeight);
    }
    
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        heightOfSubtree(root, ans);
        
        return ans;
    }
};