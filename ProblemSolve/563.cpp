/********************
 * Binary Tree Tilt *
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
    int ans = 0;
    
    //Post Order를 진행해서 제일 밑에 있는 값부터 tilt 값을 계산한다
    //모든 tilt 값을 정답에 더한다
    int calSum(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        
        //Post Order
        int left = calSum(root -> left);
        int right = calSum(root -> right);        
        
        //tilt 값 계산    
        int tilt = abs(right - left);
        
        ans += tilt;
        
        //tilt 값은 모든 subtree의 val 값의 합을 기준으로 계산되므로
        //subtree의 val 값과 left, right subtree의 합으로 갱신하면서 진행한다
        return root -> val + left + right;
    }
    
    int findTilt(TreeNode* root) {
        calSum(root);
        
        return ans;
    }
};