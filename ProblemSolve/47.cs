/*******************
 * Permutations II *
 *******************/

public class Solution {
    public void Swap(ref int a, ref int b){
        int temp = a;
        a = b;
        b = temp;
    }
    
    public void Backtracking(ref List<IList<int>> ans, int[] num, int start, int end){
        if(start == end - 1){
            ans.Add(new List<int>(num.ToList()));
            return;
        }
        
        for(int i=start; i<end; ++i){
            if(i != start && num[i] == num[start]){
                continue;
            }
            
            Swap(ref num[i], ref num[start]);
            Backtracking(ref ans, (int[])num.Clone(), start + 1, end);
        }
    }
    
    public IList<IList<int>> PermuteUnique(int[] nums) {
        Array.Sort(nums);
        List<IList<int>> ans = new List<IList<int>>();
        
        Backtracking(ref ans, nums, 0, nums.Length);
        return ans;
    }
}