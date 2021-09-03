/**********************
 * Sum of Left Leaves *
 **********************/

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
    int sumOfLeftLeaves(TreeNode* root, bool isLeft = false) {
        if(root == NULL){
            return 0;
        }
        int sum = 0;
        
        //leaf이면서 left 노드인지 확인
        if(root -> left == NULL && root -> right == NULL && isLeft){
            sum = root -> val;
        }
        
        //모든 tree를 순회하면서 left leaf 값을 더한다
        sum = sum + sumOfLeftLeaves(root -> left, true) + sumOfLeftLeaves(root -> right, false);
        
        return sum;
    }
};