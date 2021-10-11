/***************************
 * Diameter of Binary Tree *
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
    //tree에서 dpeth값을 이용해 최대 diameter 값을 구한다
    int maxDiameter(TreeNode* root, int& diameter){
        if(root == NULL){
            return 0;
        }
        //left subtree에서 maximum depth값을 찾고
        int leftDepth = maxDiameter(root -> left, diameter);
        //right subtree에서 maximum depth값을 찾는다
        int rightDepth = maxDiameter(root -> right, diameter);
        
        //위에서 구한 leftDepth와 rightDepth를 더하면 
        //현재 root에서 나올 수 있는 최대 diameter값이다
        //기존에 구한 diameter와 비교해서 더 큰 값을 diameter로 저장한다
        diameter = max(diameter, leftDepth + rightDepth);
        
        //depth값을 갱신한다
        //현재 root를 기준으로 left, right depth값에 1을 더하면 현재 root에서
        //구할 수 있는 최대 depth값을 구할 수 있다
        return max(leftDepth, rightDepth) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        
        maxDiameter(root, ans);
        
        return ans;
    }
};