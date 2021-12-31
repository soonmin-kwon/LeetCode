/************************************************
 * Maximum Difference Between Node and Ancestor *
 ************************************************/

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
    int ans = 0;
    
    int getMaxAncestorDiff(TreeNode* root, int maximum, int minimum){
        if(root == NULL){
            return maximum - minimum;
        }
        
        maximum = max(root->val, maximum);
        minimum = min(root->val, minimum);
        
        int leftMax = getMaxAncestorDiff2(root->left, maximum, minimum);
        int rightMax = getMaxAncestorDiff2(root->right, maximum, minimum);
        return max(leftMax, rightMax);
    }
    
    void getMaxAncestorDiff(TreeNode* root, int maximum, int minimum){
        if(root == NULL){
            return;
        }
        
        int ansTemp = max(abs(maximum - root->val), abs(minimum - root->val));
        ans = max(ans, ansTemp);
        
        maximum = max(maximum, root->val);
        minimum = min(minimum, root->val);
        getMaxAncestorDiff(root->left, maximum, minimum);
        getMaxAncestorDiff(root->right, maximum, minimum);
        return;
    }
    
    int maxAncestorDiff(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        
        getMaxAncestorDiff(root, root->val, root->val);
        return ans;
    }
};