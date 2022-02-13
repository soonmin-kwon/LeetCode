/***********
 * Subsets *
 ***********/

public class Solution {
    public void Backtracking(ref List<IList<int>> ans, List<int> currSet, int[] nums, int startIdx){
        if(startIdx > nums.Length){
            return;
        }
        
        ans.Add(new List<int>(currSet));
        
        for(int i=startIdx; i<nums.Length; ++i){
            currSet.Add(nums[i]);
            Backtracking(ref ans, currSet, nums, i + 1);
            currSet.RemoveAt(currSet.Count - 1);
        }
        
        return;
    }
    
    public IList<IList<int>> Subsets(int[] nums) {
        List<IList<int>> ans = new List<IList<int>>();
        List<int> currSet = new List<int>();        
        
        Backtracking(ref ans, currSet, nums, 0);
        
        return ans;
    }
}