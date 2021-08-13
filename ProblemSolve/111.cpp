/********************************
 * Minimum Depth of Binary Tree *
 ********************************/

class Solution {
public:
    //BFS
    int minDepth(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        
        if(root == NULL){
            return 0;
        }
        
        int curDepth = 1;
        TreeNode* temp;
        
        q.push(make_pair(root, curDepth));
        
        while(!q.empty()){
            temp = q.front().first;
            curDepth = q.front().second;
            
            q.pop();
            
            if(temp -> left == NULL && temp->right == NULL){
                return curDepth;
            }
            
            if(temp -> left != NULL){
                q.push(make_pair(temp -> left, curDepth+1));
            }
            
            if(temp -> right != NULL){
                q.push(make_pair(temp -> right, curDepth+1));
            }            
        }
        
        return curDepth;
    }
    
    //DFS
    int minDepth2(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        
        int leftMin = minDepth(root -> left);
        int rightMin = minDepth(root -> right);
        
        if(leftMin == 0 || rightMin == 0){
            return max(leftMin, rightMin) + 1;
        }
        
        return min(leftMin, rightMin) + 1;
    }
};