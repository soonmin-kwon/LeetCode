/**********************************
 * Binary Tree Preorder Traversal *
 **********************************/

class Solution {
public:
    //재귀 O
    void preorder(vector<int>& ans, TreeNode* root){     
        ans.push_back(root -> val);
        if(root -> left != NULL){
            preorder(ans, root -> left);
        }
        if(root -> right != NULL){
            preorder(ans, root -> right);
        }
        
        return;
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        
        preorder(ans,root);
        
        return ans;
    }
    
    //재귀 X
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> ans;
        if(root == NULL) {
            return ans;
        }
        
        s.push(root);
        
        TreeNode* temp;
        
        //벡터에 root의 val을 넣고 stack에 right, left 순으로 넣으면 left -> right 순으로 진행 가능
        while(!s.empty()){
            temp = s.top();
            ans.push_back(temp->val);
            s.pop();
            
            if(temp -> right != NULL){
                s.push(temp -> right);
            }
            
            if(temp -> left != NULL){
                s.push(temp -> left);
            }
        }
        
        return ans;
    }
};