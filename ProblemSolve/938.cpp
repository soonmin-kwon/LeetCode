/********************
 * Range Sum of BST *
 ********************/

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
    int rangeSumBST(TreeNode* root, int low, int high, int sum = 0) {
        if(root == NULL){
            return sum;
        }
                
        if(root -> val < low){
            //BST이기 때문에 left subtree의 모든 node 값은 범위 밖의 값이다
            sum = rangeSumBST(root -> right, low, high, sum);
        }        
        else if(root -> val > high){
            //BST이기 때문에 right subtree의 모든 node 값은 범위 밖의 값이다        
            sum = rangeSumBST(root -> left, low, high, sum);
        }
        else{
            sum += root -> val;
            sum = rangeSumBST(root -> right, low, high, sum);
            sum = rangeSumBST(root -> left, low, high, sum);
        }
        
        return sum;
    }
};