/***************************
 * Find Duplicate Subtrees *
 ***************************/

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
    //모든 subtree를 찾아서 hash에 올리고 이미 hash에 있는 subtree인 경우 정답에 추가한다
    string dfs(TreeNode* root, vector<TreeNode*>& ans, unordered_map<string, int>& hash){
        if(root == NULL){
            return ",";
        }
        //leftSubtree를 찾는다
        string leftSub = dfs(root -> left, ans, hash);
        //rightSubtree를 찾는다
        string rightSub = dfs(root -> right, ans, hash);
        
        //subtree를 string타입으로 확인하기 위해 node사이에 ,를 추가해 하나의 string으로 만든다
        string subtree = to_string(root -> val) + "," + leftSub + "," + rightSub;
        
        //중복을 방지하기 위해 1일때만 정답에 추가한다
        //hash[subtree] == 1이면 이미 존재하는 subtree이다
        if(hash[subtree] == 1){
            ans.push_back(root);
        }
        
        hash[subtree]++;
        return subtree;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ans;
        unordered_map<string, int> hash;
        
        if(root == NULL){
            return ans;
        }
        
        dfs(root, ans, hash);
        
        return ans;
    }
};