/***************
 * Path Sum II *
 ***************/

class Solution {
public:
    void path(TreeNode* root, int targetSum, int curSum, vector<int>& p, vector<vector<int>>& ans) {
        if(root == NULL){
            return;
        }
        
        //경로 벡터에 넣어주고
        p.push_back(root->val);
        curSum += root -> val;
        
        //리프일때만 답이 되기 때문에 리프인지 체크
        if(root -> left == NULL && root -> right == NULL && curSum == targetSum){
            ans.push_back(p);
            //원상태로 바꾼다.
            p.pop_back();
            return;
        }
        
        path(root -> left, targetSum, curSum, p, ans);
        path(root -> right, targetSum, curSum, p, ans);
        
        //다시 원상태로 바꾸고 리턴한다.
        p.pop_back();
        
        return;
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> p;
        
        path(root, targetSum, 0, p, ans);
        return ans;
    }
};