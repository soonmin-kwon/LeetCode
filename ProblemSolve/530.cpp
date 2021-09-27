/**************************************
 * Minimum Absolute Difference in BST *
 **************************************/

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
    //inorder traversal을 하면서 minDiff을 계산한다
    //현재 root를 기준으로 left subtree는 전부 작은 값, right subtree는 전부 큰 값이다.
    //minDiff은 최대한 가까운 수끼리 계산을 해야하고 inorder traversal은 left, root, right 순이다.
    //left subtree를 inorder traversal하면서 마지막에 도착하는 값은 left subtree에서 제일 큰 값이고
    //right subtree를 시작하는 값은 right subtree에서 제일 작은 값이다.
    //두 수 모두 root를 기준으로 가장 가까운 수이기 때문에 두 수를 기준으로 minDiff을 계산한다
    void calMinDiff(TreeNode* root, int& prevVal, int& minDiff){
        if(root == NULL){
            return;
        }
        
        //left subtree
        calMinDiff(root -> left, prevVal, minDiff);
        
        //처음 prevVal이 초기화 되어있는 상태에서는 minDiff을 계산하면 안 된다
        //모든 node는 항상 >=0이기 때문에 처음의 경우를 제외하면 항상 거치게 된다
        if(prevVal >= 0){
            minDiff = min(minDiff, root -> val - prevVal);
        }
        //위의 계산 root -> val - prevVal이 항상 양수가 나오도록 prevVal값을 미리 갱신한다
        prevVal = root -> val;
        
        //right subtree
        calMinDiff(root -> right, prevVal, minDiff);
        
        return;
    }
    
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX;
        int prevVal = -1;
        
        calMinDiff(root, prevVal, ans);
        
        return ans;
    }
};