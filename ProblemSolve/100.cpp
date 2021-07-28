/*************
 * Same Tree *
 *************/

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //예외 처리
        if(p == NULL && q == NULL){
            return true;
        }
        
        if(p == NULL && q!= NULL){
            return false;
        }
        
        if(p != NULL && q == NULL){
            return false;
        }
        
        //현재 노드의 value가 같으면, 같은 위치의 노드에 접근하기 때문에 값을 비교해 다른지 체크
        if(p->val == q->val){
            //재귀를 이용해 접근
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
        
        return false;
    }
};