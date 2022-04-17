/********************************
 * Increasing Order Search Tree *
 ********************************/

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
    vector<int> sortBST(TreeNode* root, vector<int>& sortedBST){
        if(root == NULL){
            return {};
        }
        
        sortBST(root -> left, sortedBST);
        sortedBST.push_back(root -> val);
        sortBST(root -> right, sortedBST);
        
        return sortedBST;
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> sortedBST;
        sortBST(root, sortedBST);
        
        TreeNode* ans = new TreeNode(0);
        TreeNode* curNode = ans;
        for(int node : sortedBST){
            curNode -> right = new TreeNode(node);
            curNode = curNode -> right;
        }
        
        return ans -> right;
    }
};