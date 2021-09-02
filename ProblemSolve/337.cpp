/********************
 * House Robber III *
 ********************/

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
    //pair<현재 노드 선택, 현재 노드 선택 x> 값 리턴
    pair<int, int> calMax(TreeNode* root) {
        if(root == NULL){
            return {0, 0};
        }
        
        pair<int, int> left = calMax(root -> left);     //left subtree를 계산
        pair<int, int> right = calMax(root -> right);   //right subtee를 계산
        
        //현재 node를 선택하는 경우에는 child를 선택할 수 없다
        int choose = root -> val + left.second + right.second;
        
        //현재 node를 선택하지 않는 경우에는 child도 선택하지 않을 수 있으므로 child를 선택하는 경우, 선택하지 않는 경우 중 큰 값을 택한다
        int noChoose = max(left.first , left.second) + max(right.first, right.second);
        
        return {choose, noChoose};
    }
    
    int rob(TreeNode* root) {
        return max(calMax(root).first, calMax(root).second);
    }
};