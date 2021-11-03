/****************************
 * Sum Root to Leaf Numbers *
 ****************************/

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
    int sumNumbers(TreeNode* root, int curSum = 0) {
        if(root == NULL){
            return 0;
        }
        
        int ans = 0;
        
        do{
            if(root -> left != NULL){
                break;
            }
            
            if(root -> right != NULL){
                break;
            }
                        
            //leaf인 경우
            ans += curSum + root -> val;
            return ans;
            
        }while(false);   
        
        //DFS
        ans = sumNumbers(root -> left, (curSum + root -> val) * 10) + sumNumbers(root -> right, (curSum + root -> val) * 10);
        
        return ans;
    }
};