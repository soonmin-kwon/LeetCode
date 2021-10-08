/******************************************
 * Binary Search Tree to Greater Sum Tree *
 ******************************************/

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
    int sum = 0;
    
    //현재 node의 val보다 큰 값들의 sum을 현재 node의 val에 더한다
    //binary search tree이기 때문에 맨 오른쪽에 있는 node가 가장 크다
    //맨 오른쪽에 있는 node에 먼저 도달후 sum값을 조정해 최종적으로 node의 val값을 수정한다
    TreeNode* bstToGst(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }
        
        //right subtree로 이동
        bstToGst(root -> right);
        
        //기존 sum에 현재 node의 val을 더해 지속 갱신한다
        sum += root -> val;
        root -> val = sum;
        
        //left subtree는 현재 node보다 작은 값이기 때문에 현재 node까지 계산된 sum을 이용해 갱신한다
        bstToGst(root -> left);
        
        return root;
    }
};