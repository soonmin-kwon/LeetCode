/**********************
 * Invert Binary Tree *
 **********************/

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }
        
        TreeNode* temp;
        
        //왼쪽 서브트리, 오른쪽 서브트리 둘 중 하나라도 존재하면 바꿔야 한다
        if(root -> left != NULL || root -> right != NULL){
            temp = root -> right;
            root -> right = root -> left;
            root -> left = temp;
        }
        //모두 존재하지 않으면 현재 root를 리턴
        else{
            return root;
        }
        
        //바뀐 트리에서도 진행해야 한다
        if(root -> left != NULL){
            invertTree(root -> left);
        }
        
        if(root -> right != NULL){
            invertTree(root -> right);
        }
        
        return root;
    }
};