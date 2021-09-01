/**************************
 * Cousins in Binary Tree *
 **************************/

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
    //x, y의 depth, parent 값을 저장
    vector<pair<int, int>> mem;
    
    void findNode(TreeNode* root, int x, int y, int depth, int parent) {
        if(root == NULL){
            return;
        }
        
        //찾는 값이면 vector에 추가
        if(root -> val == x || root -> val == y){
            mem.push_back(make_pair(depth, parent));            
        }
        
        //모든 노드 탐색
        findNode(root -> left, x, y, depth + 1, root -> val);
        findNode(root -> right, x, y, depth + 1, root -> val);
        
        return;
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        findNode(root, x, y, 0, -1);
        
        //조건에 부합하는지 확인
        if(mem[0].first == mem[1].first && mem[0].second != mem[1].second){
            return true;
        }
        
        return false;
    }
};