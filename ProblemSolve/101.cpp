/******************
 * Symmetric Tree *
 ******************/

class Solution {
public:
    bool checkSymmetric(TreeNode* leftSub, TreeNode* rightSub){
        
        //서로 null, 무사히 끝까지 도달하면
        if(leftSub == NULL & rightSub == NULL){
            return true;
        }
        else if(leftSub == NULL || rightSub == NULL){
            return false;
        }
        else if(leftSub -> val != rightSub -> val){
            return false;
        }
        
        //왼쪽의 왼쪽, 오른쪽의 왼쪽을 비교, 왼쪽의 오른쪽, 오른쪽의 오른쪽을 비교
        return checkSymmetric(leftSub -> left, rightSub -> right) && checkSymmetric(leftSub -> right, rightSub -> left);
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        
        return checkSymmetric(root -> left, root -> right);                        
    }
};