/************
 * Path Sum *
 ************/

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        //NULL이면 false
        if(root == NULL){
            return false;
        }
        
        //leaf면 targetSum을 만족하는지 확인
        if(root -> left == NULL && root -> right == NULL){
            return (targetSum - root->val) == 0;
        }                
        
        //targetSum을 현재 root의 값을 빼면서 진행, 0이 되면 만족
        return hasPathSum(root -> left, targetSum - root->val) || hasPathSum(root -> right, targetSum - root->val);
    }
};