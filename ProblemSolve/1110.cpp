/***********************************
 * Delete Nodes And Returns Forest *
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
    vector<TreeNode*> ans;  //정답 벡터
    unordered_set<int> to_del;  //hash table
    
    //먼저 가장 깊은 곳까지 탐색하기 때문에 해당되는 노드는 바로 바로 지우면서 진행
    void dfs(TreeNode* &root) {
        if(root == NULL){
            return;
        }                
        
        //모든 node 탐색
        dfs(root -> left);
        dfs(root -> right);
        
        //만약 지금 탐색한 node가 지워야 하는 대상이면 left, right를 저장하고 현재 node를 지운다
        if(to_del.find(root -> val) != to_del.end()){
            if(root -> left != NULL){
                ans.push_back(root -> left);                
            }
            
            if(root -> right != NULL){
                ans.push_back(root -> right);
            }
            
            root = NULL;
            delete root;
        }
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        int len = to_delete.size();
        
        for(int i=0; i<len; i++){
            to_del.insert(to_delete[i]);
        }
        
        dfs(root);
        
        //남아있는 root 삽입
        if(root){
            ans.push_back(root);
        }
        
        return ans;
    }
};