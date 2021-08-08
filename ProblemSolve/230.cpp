/*********************************
 * Kth Smallest Element in a BST *
 *********************************/

class Solution {
public:
    //morris inorder traversal
    vector<int> morrisInorder(TreeNode* root){
        TreeNode* current = root;
        vector<int> temp;
        
        if(root == NULL){
            return temp;
        }
        
        while(current != NULL){
            if(current->left == NULL){
                temp.push_back(current->val);
                current = current -> right;
            }
            else{
                TreeNode* leftSub = current -> left;
                
                while(leftSub->right != current && leftSub->right !=NULL){
                    leftSub = leftSub -> right;
                }
                
                if(leftSub->right == current){
                    leftSub->right = NULL;
                    temp.push_back(current->val);
                    current = current -> right;
                }
                else{
                    leftSub->right = current;
                    current = current -> left;
                }
                                
            }
        }
        
        return temp;
    }
    
    //inorder traversal
    void inorder(vector<int>& ans, TreeNode* root) {
        if(root == NULL){
            return;
        }
        
        inorder(ans, root -> left);
        ans.push_back(root->val);
        inorder(ans, root->right);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        
        //inorder 순서로 벡터를 만든다
        ans = morrisInorder(root);
        
        //k번째 숫자를 찾는다
        return ans[k - 1];
    }
};