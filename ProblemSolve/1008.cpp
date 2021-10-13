/********************************************************
 * Construct Binary Search Tree from Preorder Traversal *
 ********************************************************/

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
    //preorder 배열을 순서대로 접근하기 위해 idx 사용
    //&idx로 사용해 전역변수처럼 사용
    //bst이기 때문에 pivot값을 기준으로 한 root의 left subtree는 전부 pivot값보다 작도록 설정
    TreeNode* constructBST(vector<int>& preorder, int& idx, int pivot){
        //pivot값보다 큰 값이면 tree에 추가할 수 없다
        if(idx == preorder.size() || preorder[idx] > pivot){
            return NULL;
        }
        
        //preorder[idx] 값을 사용했기 때문에 다음 값으로 이동
        TreeNode* root = new TreeNode(preorder[idx]);
        idx++;
        
        //현재 root를 기준으로 left subtree의 값은 현재 root 값보다 작아야만 한다
        root -> left = constructBST(preorder, idx, root -> val);
        //현재 root를 기준으로 right subtree에 있더라도 기존 pivot 값보다는 작아야만 한다
        root -> right = constructBST(preorder, idx, pivot);
        
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx = 0;
        
        return constructBST(preorder, idx, INT_MAX);
    }
};