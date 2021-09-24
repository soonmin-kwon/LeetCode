/**********************
 * Combination Sum II *
 **********************/

class Solution {
public:
    //backtracking하면서 모든 경우의 수를 찾는다
    void makeCombination(vector<vector<int>>& ans, vector<int>& candidates, vector<int>& curCombination, int idx, int target){
        //curCombination의 모든 element의 합이 target인 경우 정답에 추가
        if(target == 0){
            ans.push_back(curCombination);
            return;
        }
        
        //현재 인덱스를 기준으로 가능한 경우의 수를 모두 구한다
        for(int i=idx; i<candidates.size(); i++){                        
            //중복 제거
            if(i > idx && candidates[i] == candidates[i - 1]){
                continue;
            }
            
            //절대로 target을 만들 수 없는 경우
            if(candidates[i] > target){
                break;
            }
            
            curCombination.push_back(candidates[i]);
            makeCombination(ans, candidates, curCombination, i + 1, target - candidates[i]);
            curCombination.pop_back();
        }
        
        return;
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        
        vector<vector<int>> ans;
        vector<int> curCombination;
        makeCombination(ans, candidates, curCombination, 0, target);
        
        return ans;
    }
};