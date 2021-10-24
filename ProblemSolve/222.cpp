/*****************************
 * Count Complete Tree Nodes *
 *****************************/

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
    int countNodes(TreeNode* root) {
        //시작시 NULL인 경우는 0을 리턴한다
        if(root == NULL){
           return 0;
        }
        
        int numOfLeft = 0, numOfRight = 0;
        
        //left node가 있는 경우에만 탐색한다
        if(root -> left != NULL){
            numOfLeft = countNodes(root -> left);
        }
        
        //right node가 있는 경우에만 탐색한다
        if(root -> right != NULL){
            numOfRight = countNodes(root -> right);
        }
        
        //자기 자신 + 왼쪽 subtree의 node 개수 + 오른쪽 subtree의 node 개수
        //leaf인 경우 1 + 0 + 0이고 leaf의 parent는 1 또는 2가 된다
        //이런식으로 계속 올라가서 root에서 모든 node의 개수를 구할 수 있다
        return 1 + numOfLeft + numOfRight;
    }
};