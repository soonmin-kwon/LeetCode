/**********************************************************************
 * Find a Corresponding Node of a Binary Tree in a Clone of That Tree *
 **********************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* ans;
    TreeNode* target;
    
    void inorder(TreeNode* original, TreeNode* cloned){
        if(original == NULL){
            return;
        }
        
        inorder(original -> left, cloned -> left);
        
        if(original == target){
            ans = cloned;
            return;
        }
        
        inorder(original -> right, cloned -> right);
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        this -> target = target;
        
        inorder(original, cloned);
        
        return ans;
    }
};