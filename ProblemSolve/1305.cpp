/*******************************************
 * All Elements in Two Binary Search Trees *
 *******************************************/

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
    void getElementsAscending(TreeNode* root, vector<int>& list){
        if(root == NULL){
            return;
        }
        
        if(root -> left != NULL){
            getElementsAscending(root -> left, list);
        }
        
        list.push_back(root -> val);
        
        if(root -> right != NULL){
            getElementsAscending(root -> right, list);
        }
        
        return;
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> listForRoot1;
        vector<int> listForRoot2;
        vector<int> ans;
        
        getElementsAscending(root1, listForRoot1);
        getElementsAscending(root2, listForRoot2);
        
        int len1 = listForRoot1.size();
        int len2 = listForRoot2.size();
        int idx1 = 0;
        int idx2 = 0;
        
        while(idx1 < len1 && idx2 < len2){
            if(listForRoot1[idx1] >= listForRoot2[idx2]){
                ans.push_back(listForRoot2[idx2]);
                idx2++;
            }
            else{
                ans.push_back(listForRoot1[idx1]);
                idx1++;
            }
        }
     
        while(idx1 < len1){
            ans.push_back(listForRoot1[idx1]);
            idx1++;
        }
        
        while(idx2 < len2){
            ans.push_back(listForRoot2[idx2]);
            idx2++;
        }
        
        return ans;
    }
};