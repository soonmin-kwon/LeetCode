/*********************
 * Binary Tree Paths *
 *********************/

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
    vector<string> ans;
    
    void traversal(TreeNode* root, string path){
        if(root == NULL){
            return;
        }
        
        //leaf이면 정답에 추가
        if(root -> left == NULL && root -> right == NULL){
            path += to_string(root -> val);
            ans.push_back(path);
            return;
        }
        
        //DFS
        traversal(root -> left, path +  to_string(root -> val) + "->");
        traversal(root -> right, path + to_string(root -> val) + "->");
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == NULL){
            return {};
        }

        traversal(root, "");
        
        return ans;
    }
};