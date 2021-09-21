/***********************
 * Add One Row to Tree *
 ***********************/

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
    //DFS 방식으로 트리를 순회하면서 추가해야 하는 depth(targetDepth) 바로 전 depth에 도착하면
    //child를 추가해서 원하는 targetDepth에 val 값을 삽입한다.
    void insertVal(TreeNode* root, int val, int targetDepth, int curDepth){
        if(root == NULL){
            return;
        }
        
        //이전 depth에 도착했으면
        if(curDepth == targetDepth - 1){
            //원래 left subtree를 따로 저장한 뒤에
            TreeNode* temp = root -> left;
            
            //현재 subtree의 left에 val값을 삽입하고
            root -> left = new TreeNode(val);
            
            //left의 left로 원래 left subtree를 추가해 한 row를 추가한 것과 동일하게 만든다
            root -> left -> left = temp;
            
            //위의 left subtree 케이스와 같음
            temp = root -> right;
            root -> right = new TreeNode(val);
            root -> right -> right = temp;
            
            return;
        }
        
        //DFS 방식으로 트리 순회
        insertVal(root -> left, val, targetDepth, curDepth + 1);
        insertVal(root -> right, val, targetDepth, curDepth + 1);
        
        return;
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        //depth가 1인 경우에는 left subtree로 기존에 있던 tree가 추가된다.
        if(depth == 1){
            TreeNode* ans = new TreeNode(val, root, NULL);
            return ans;            
        }
        
        insertVal(root, val, depth, 1);
        
        return root;
    }
};