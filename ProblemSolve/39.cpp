/*******************
 * Combination Sum *
 *******************/

class Solution {
public:
    //Backtracking
    //중복을 방지하기 위해 idx를 이용해 뒤로 돌아가는 상황을 제어한다
    //target에서 candidates[i]값을 빼면서 0이 되면 정답에 추가한다    
    void combination(vector<vector<int>>& ans, vector<int>& candidates, vector<int>& combi, int target, int idx){
        if(idx == candidates.size() || target < 0){
            return;
        }
        
        if(target == 0){
            ans.push_back(combi);
            return;
        }
        
        for(int i=idx; i<candidates.size(); i++){
            combi.push_back(candidates[i]);
            combination(ans, candidates, combi, target - candidates[i], i);
            combi.pop_back();
        }
        
        return;
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;        
        vector<int> temp;
        
        for(int i=0; i<candidates.size(); i++){
            temp.push_back(candidates[i]);
            combination(ans, candidates, temp, target - candidates[i], i);
            temp.pop_back();
        }
        
        return ans;
    }
};