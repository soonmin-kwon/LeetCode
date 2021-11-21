/**************************************************************
 * Construct Binary Tree from Inorder and Postorder Traversal *
 **************************************************************/

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
    TreeNode* makeTree(vector<int>& inorder, vector<int>& postorder, int leftIn, int rightIn, int leftPo, int rightPo){
        if(leftIn > rightIn || leftPo > rightPo){
            return NULL;
        }
        
        TreeNode* node = new TreeNode(postorder[rightPo]);
        
        int border = leftIn;
        //inorder에서 root값을 찾으면, 그 값을 기준으로 left, right가 나뉜다
        while(node->val != inorder[border]){
            border++;
        }
        
        //위에서 root값을 기준으로 left의 길이, right의 길이를 찾았으므로
        //postorder에서 left, right범위만 살펴보면된다.
        node -> left = makeTree(inorder, postorder, leftIn, border-1, leftPo, leftPo+border-leftIn-1);
        node -> right = makeTree(inorder, postorder, border+1, rightIn, leftPo+border-leftIn, rightPo-1);
        
        return node;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return makeTree(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
    }
};