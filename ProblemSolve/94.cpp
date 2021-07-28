/*********************************
 * Binary Tree Inorder Traversal *
 *********************************/

//참고 https://stackoverflow.com/questions/5502916/explain-morris-inorder-tree-traversal-without-using-stacks-or-recursion

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
    //정답 벡터
    vector<int> ans1;
    //재귀를 이용한 inorder
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == nullptr){
            return ans1;
        }
        
        if(root->left != nullptr){
            inorderTraversal(root -> left);
        }
        
        ans1.push_back(root->val);
        
        if(root->right!=nullptr){
            inorderTraversal(root->right);
        }
        
        return ans1;
    }
    
    /*
    Morris inorder Traversal    
    
                   A
            B              E
        C       D      F       G
        
                    
            B             
        C       D     
                    A
                B       E
             C    D   F    G
             
        C     
            B             
                D     
                    A
                       E
                    F    G            
            
        C     
            B             
                D     
                    A
                       F    
                         E
                           G
    */
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* current = root;
        vector<int> ans;
        if(root == nullptr){
            return ans;
        }
                
        while(current != nullptr){
            if(current -> left == nullptr){
                ans.push_back(current->val);
                current = current->right;
            }
            else {  
                TreeNode* leftSub = current->left;

                while( leftSub -> right != current && leftSub -> right != nullptr){
                    leftSub = leftSub -> right;
                }
                                    
                if(leftSub -> right == current){    
                    leftSub->right = nullptr;
                    ans.push_back(current->val);
                    current = current -> right;
                }        
                else {  
                    leftSub->right = current;
                    current = current -> left;
                }
            }
        }                
        return ans;
    }
};