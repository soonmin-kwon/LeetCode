/***********************
 * Combination Sum III *
 ***********************/

class Solution {
public:
    void backtracking(vector<vector<int>>& ans, vector<int> curCandidates, int idx, int curSum, int k, int n){
        if(curSum == n && curCandidates.size() == k){
            ans.push_back(curCandidates);
            return;
        }
        
        if(curCandidates.size() >= k){
            return;
        }
        
        for(int i=idx; i<=9; ++i){
            curCandidates.push_back(i);
            backtracking(ans, curCandidates, i + 1, curSum + i, k, n);
            curCandidates.pop_back();
        }
        
        return;
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> curCandidates;
        
        backtracking(ans, curCandidates, 1, 0, k, n);
        return ans;
    }
};