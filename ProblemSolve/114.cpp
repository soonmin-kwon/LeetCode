/**************************************
 * Flatten Binary Tree to Linked List *
 **************************************/

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
    //현재 tree에서 right leaf에 기존 right를 붙여넣는다
    void moveRight(TreeNode* root, TreeNode* right){
        //right leaf로 이동
        while(root -> right != NULL){
            root = root -> right;
        }
        
        //기존 right 붙여넣기
        root -> right = right;
        return;
    }
    
    //left를 right에 붙이고 기존 right를 
    //새로 생긴 right의 leaf다음에 붙여넣는다
    //이 방법을 끝까지 계속하면 flatten한 tree가 완성된다
    void flatten(TreeNode* root) {
        if(root == NULL){
            return;
        }
        
        //기존 right를 저장
        TreeNode* rightSubTree = root -> right;
        
        //left를 right에 붙인다
        root -> right = root -> left;
        //left를 끊어준다
        root -> left = nullptr;
        
        //새로 생긴 right의 right leaf에 기존 right를 붙인다
        moveRight(root, rightSubTree);
        //재귀적으로 반복
        flatten(root -> right);
        
        return;
    }
};