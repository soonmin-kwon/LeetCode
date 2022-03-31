/********************************
 * Sum of All Subset XOR Totals *
 ********************************/

public class Solution {
    int ans = 0;
    
    public void Backtracking(int[] nums, int idx, int curXor){
        if(idx >= nums.Length){
            return;
        }
        
        for(int i=idx; i<nums.Length; ++i){
            ans += (curXor ^ nums[i]);
            Backtracking(nums, i + 1, curXor ^ nums[i]);
        }
    }
    
    public int SubsetXORSum(int[] nums) {
        Backtracking(nums, 0, 0);
        
        return ans;
    }
}