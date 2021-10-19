/***************************
 * Subtree of Another Tree *
 ***************************/

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
    //현재 root에서 dfs 방식으로 탐색했을때 sub를 찾을 수 있는지 확인한다
    bool isEqual(TreeNode* root, TreeNode* sub){
        //두개의 값이 같이 NULL이 되면 같이 끝난다는 뜻
        //서로 다르게 NULL이 되면 root에서 시작하면 sub를 찾을 수 없다는 뜻
        if(root == NULL || sub == NULL){
            return root == sub;
        }
        
        //sub와 root가 가리키는 값이 같아야하고 이 기준은 모든 node에서 적용되어야만 한다
        return root -> val == sub -> val && isEqual(root -> left, sub -> left) && isEqual(root -> right, sub -> right);
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL){
            return false;
        }
        
        //주어진 root의 모든 node를 돌면서 현재 node에서부터 subRoot를 찾을 수 있는지 isEqual로 확인하고
        //모든 node를 돌기 위해 isSubtree를 dfs 방식으로 탐색한다
        return isEqual(root, subRoot) || isSubtree(root -> left, subRoot) || isSubtree(root -> right, subRoot);
    }
};