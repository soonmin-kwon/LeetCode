public class Solution {
    public void Backtracking(ref List<IList<int>> ans, int[] candidates, List<int> combination, int goal, int idx){
        if(goal < 0 || idx == candidates.Length){
            return;
        }
        
        if(goal == 0){
            ans.Add(new List<int>(combination));
        }
        
        for(int i=idx; i<candidates.Length; ++i){
            combination.Add(candidates[i]);
            Backtracking(ref ans, candidates, combination, goal - candidates[i], i);
            combination.RemoveAt(combination.Count - 1);
        }
        
        return;
    }
    
    public IList<IList<int>> CombinationSum(int[] candidates, int target) {
        List<IList<int>> ans = new List<IList<int>>();
        
        List<int> combination = new List<int>();
        
        for(int i=0; i<candidates.Length; ++i){
            combination.Add(candidates[i]);
            Backtracking(ref ans, candidates, combination, target - candidates[i], i);
            combination.RemoveAt(combination.Count - 1);
        }
        
        return ans;
    }
}