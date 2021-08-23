/*******************************
 * Two Sum IV - Input is a BST *
 *******************************/

class Solution {
public:
    //hash table
    unordered_set<int> set;
    
    bool traverse(TreeNode* root, int k){
        if(root == NULL){
            return false;
        }        
        
        //hash에 현재 root의 val이 있는지 확인
        if(set.find(root -> val) == set.end()){
            //없으면 찾아야하는 수를 insert
            set.insert(k - root -> val);
        }
        else{
            return true;
        }
        
        return traverse(root -> left, k) || traverse(root -> right , k);
    }
    
    bool findTarget(TreeNode* root, int k) {
        return traverse(root, k);
    }
};