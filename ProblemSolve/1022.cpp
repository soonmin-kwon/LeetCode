/**************************************
 * Sum of Root To Leaf Binary Numbers *
 **************************************/

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
    int sumRootToLeaf(TreeNode* root, int curSum = 0)  {        
        if(root == NULL){
            return 0;
        }
        
        //leaf인 경우 합 계산
        if(root -> left == NULL && root -> right == NULL){
            return 2 * curSum + root -> val;
        }
        
        //재귀적으로 sum 계산하면서 진행
        return sumRootToLeaf(root->left, 2 * curSum + root -> val) + sumRootToLeaf(root->right, 2 * curSum + root -> val);
    }
};