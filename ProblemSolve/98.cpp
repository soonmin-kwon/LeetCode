/*******************************
 * Validate Binary Search Tree *
 *******************************/

//inorder로 정렬 후에 제대로 정렬되어있는지 확인하는 방법
class Solution {
public: 
    vector<int> ans;
    //Morris InOrderTraversal    
    void inOrder(TreeNode* root){
        TreeNode* current = root;        
        
        if(root == NULL){
            return;
        }
        
        while(current != NULL){
            if(current -> left == NULL){
                ans.push_back(current->val);
                current = current -> right;
            }
            else{
                TreeNode* leftSub = current -> left;
                
                while(leftSub -> right != current && leftSub -> right != NULL){
                    leftSub = leftSub -> right;
                }
                
                if(leftSub -> right == current){
                    leftSub -> right = NULL;
                    ans.push_back(current -> val);
                    current = current -> right;
                }
                else{
                    leftSub->right = current;
                    current = current -> left;
                }
            }
        }        
    }
    
    bool isValidBST(TreeNode* root) {
        inOrder(root);
        
        int len = ans.size();
        int standard = ans[0];
        //제대로 정렬되어 있는지
        for(int i=1; i<len; i++){
            if(standard >= ans[i]){
                return false;
            }
            else{
                standard = ans[i];
            }
        }
        
        return true;
    }
    
    vector<int> order;
    //일반적인 InOrderTraversal
    void inOrder(TreeNode* root){
        if(root -> left){
            inOrder(root -> left);
        }
        
        order.push_back(root->val);
        
        if(root -> right){
            inOrder(root -> right);
        }
    }
    
    bool isValidBST(TreeNode* root) {
        inOrder(root);
        
        int len = order.size();
        int standard = order[0];
        
        for(int i=1; i<len; i++){
            if(standard >= order[i]){
                return false;
            }
            else{
                standard = order[i];
            }
        }
        
        return true;
    }
};