/************************
 * Delete Node in a BST *
 ************************/

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL){
            return NULL;
        }
        
        if(key < root -> val){
            root -> left = deleteNode(root -> left, key);
        }
        else if(key > root -> val){
            root -> right = deleteNode(root -> right, key);
        }
        else{
            //leaf인 경우
            if(root -> left == NULL && root -> right == NULL){
                return NULL;
            }
            //자식이 하나인 경우
            if(root -> left == NULL || root -> right == NULL){
                return root -> left != NULL ? root -> left : root -> right;
            }
            
            //자식이 두개인 경우 양쪽 subtree에서의 중간 값을 찾아서 root의 값으로 넣어줘야 한다.
            //left subtree에서 제일 큰 값을 찾거나, right subtree에서 가장 작은 값을 찾으면 된다.
            TreeNode* temp = root -> left;
            while(temp -> right != NULL){
                temp = temp -> right;
            }
            root -> val = temp -> val;
            root -> left = deleteNode(root -> left, temp -> val);
        }
        
        return root;
    }
};