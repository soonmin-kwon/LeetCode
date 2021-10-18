/***************************************
 * Check Completeness of a Binary Tree *
 ***************************************/

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
    //BFS 방식으로 확인
    //NULL은 마지막에만 나와야 complete binary tree
    bool isCompleteTree(TreeNode* root) {
        if(root == NULL){
            return false;
        }
        
        //마지막 null인지
        bool isLastNull = false;
                
        queue<TreeNode*> q;
        q.push(root);
        
        //BFS
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            
            //마지막 NULL인지 확인한다
            if(temp == NULL){
                isLastNull = true;
            }            
            else{
                //NULL이 이미 나온 경우 complete binary tree가 될 수 없음
                if(isLastNull){
                    return false;
                }
                
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        
        return true;
    }
};