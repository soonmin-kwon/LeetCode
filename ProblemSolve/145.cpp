/***********************************
 * Binary Tree Postorder Traversal *
 ***********************************/

class Solution {
public:
    //재귀 O
    void postorder(vector<int>& ans, TreeNode* root) {
        if(root -> left != NULL){
            postorder(ans, root -> left);
        }
        
        if(root -> right != NULL){
            postorder(ans, root -> right);
        }
        
        ans.push_back(root->val);
        return;
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        
        if(root == NULL){
            return ans;
        }
        
        postorder(ans, root);
        
        return ans;
    }
    
    //재귀 X
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        
        if(root == NULL){
            return ans;
        }
        
        TreeNode* temp;
        stack<TreeNode*> s;
        
        s.push(root);
        //postorder는 left, right, root순으로 순회하기 때문에
        //root, right, left 순으로 순회하고 정답을 뒤집어주면 left, right, root순으로 순회하는 게 된다
        while(!s.empty()){
            temp = s.top();            
            s.pop();
            
            ans.push_back(temp -> val);
            
            if(temp -> left != NULL){
                s.push(temp -> left);
            }
            
            if(temp -> right != NULL){
                s.push(temp -> right);
            }            
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};