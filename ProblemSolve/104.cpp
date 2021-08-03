/********************************
 * Maximum Depth of Binary Tree *
 ********************************/

class Solution {
public:
    //BFS
    int maxDepth(TreeNode* root) {        
        queue<pair<TreeNode*,int>> q;
        
        if(root == NULL){
            return 0;
        }
        
        q.push(make_pair(root, 1));
        TreeNode* node;
        int depth;
        int ans=0;
        
        while(!q.empty()){
            node = q.front().first;
            depth = q.front().second;
            q.pop();
            
            if(node -> left != NULL){
                q.push(make_pair(node->left, depth+1));
            }
            
            if(node->right != NULL){
                q.push(make_pair(node->right, depth+1));
            }
            
            if(node -> left == NULL && node->right == NULL){
                ans = max(ans, depth);
            }
        }
        
        return ans;
    }
    
    //DFS
    int maxDepth(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        
        int leftDepth = maxDepth(root -> left);
        int rightDepth = maxDepth(root -> right);
        
        int maximumDepth = max(leftDepth, rightDepth) + 1;
        
        return maximumDepth;        
    }
};