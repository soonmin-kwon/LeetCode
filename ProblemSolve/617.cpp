/**************************
 * Merge Two Binary Trees *
 **************************/

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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        //모두 NULL인 경우는 NULL로 설정
        if(root1 == NULL && root2 == NULL){
            return NULL;
        }
        
        //한 tree가 끝난 경우 그 아래로는 다른 tree만 존재
        if(root1 == NULL){
            return root2;
        }
        else if(root2 == NULL){
            return root1;
        }
        
        TreeNode* ans = new TreeNode(root1 -> val + root2 -> val);
        
        //left는 left끼리 비교하면서, right는 right끼리 비교하면서 진행
        ans -> left = mergeTrees(root1 -> left, root2 -> left);
        ans -> right = mergeTrees(root1 -> right, root2 -> right);
                
        return ans;
    }    
};