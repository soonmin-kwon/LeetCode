/****************
 * Path Sum III *
 ****************/

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
    
    //DFS로 tree를 순회하면서 targetSum을 만들 수 있는지 확인
    //targetSum부터 현재 root의 val 값을 빼면서 remainSum을 갱신한다
    //remainSum이 현재 root의 val과 같으면 targetSum을 만들 수 있는 경우
    void dfs(TreeNode* root, int remainSum){
        //leaf인 경우
        if(root == NULL){
            return;
        }
        
        //targetSum을 만들 수 있는 경우
        if(root -> val == remainSum){
            ans++;
        }
        
        //DFS 진행
        //reaminSum을 갱신
        dfs(root -> left, remainSum - root -> val);
        dfs(root -> right, remainSum - root -> val);
        
        return;
    }
    
    //tree의 각 node에서 DFS를 해서 targetSum이 만들어지는 path를 찾는다
    //tree의 각 node를 모두 탐색하기 위해 pathSum 역시 DFS로 진행한다
    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL){
            return 0;
        }
        
        //각 node에서 targetSum을 만들 수 있는 path가 존재하는지 확인하기 위한 DFS
        dfs(root, targetSum);
        
        //처음 주어진 tree의 모든 node를 탐색하도록 DFS 진행
        pathSum(root -> left, targetSum);
        pathSum(root -> right, targetSum);
        
        return ans;
    }
};