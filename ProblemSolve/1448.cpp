/***********************************
 * Count Good Nodes in Binary Tree *
 ***********************************/

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
    int ans = 0;
    
    //DFS로 tree를 순회하면서 good node의 개수를 센다
    void dfs(TreeNode* root, int maximum){
        if(root == NULL){
            return;
        }
        
        //현재 root까지의 path 중에 root 값이 제일 큰 값이면 good node
        if(root -> val >= maximum){            
            ans++;
            //maximum 값 갱신
            maximum = root -> val;
        }
        
        //DFS 진행
        dfs(root -> left, maximum);
        dfs(root -> right, maximum);
        
        return;
    }
    
    int goodNodes(TreeNode* root) {
        dfs(root, root -> val);
        
        return ans;
    }
};