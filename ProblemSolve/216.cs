/***********************
 * Combination Sum III *
 ***********************/

public class Solution {
    public void Backtracking(ref List<IList<int>> ans, List<int> curCandidates, int idx, int curSum, int k, int n){   
        if(curSum == n && curCandidates.Count == k){
            ans.Add(new List<int>(curCandidates));
            return;
        }
        
        if(curCandidates.Count >= k){
            return;
        }
        
         for(int i=idx; i<=9; ++i){
            curCandidates.Add(i);
            Backtracking(ref ans, curCandidates, i + 1, curSum + i, k, n);
            curCandidates.RemoveAt(curCandidates.Count - 1);
        }
    }
    
    public IList<IList<int>> CombinationSum3(int k, int n) {
        List<IList<int>> ans = new List<IList<int>>();
        
        Backtracking(ref ans, new List<int>(), 1, 0, k, n);
        return ans;
    }
}