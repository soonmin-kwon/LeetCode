/********************
 * Contiguous Array *
 ********************/

public class Solution {
    public int FindMaxLength(int[] nums) {
        Dictionary<int, int> hash = new Dictionary<int, int>();
        hash.Add(0, -1);
        int ans = 0, remainZeroCount = 0;
        
        for(int i=0; i<nums.Length; ++i){
            remainZeroCount += (nums[i] == 1 ? 1 : -1);
            
            if(hash.ContainsKey(remainZeroCount)){
                ans = Math.Max(ans, i - hash[remainZeroCount]);
            }
            else{
                hash.Add(remainZeroCount, i);
            }
        }
        
        return ans;
    }
}