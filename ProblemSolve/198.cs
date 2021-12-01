/****************
 * House Robber *
 ****************/

public class Solution {
    //전형적이고 유명한 DP 문제
    public int Rob(int[] nums) {
        if(nums.Length < 2){
            return nums[0];
        }
        
        int[] dp = new int[nums.Length];
        
        dp[0] = nums[0];
        dp[1] = Math.Max(nums[0], nums[1]);
        for(int i=2; i<nums.Length; ++i){
            dp[i] = Math.Max(dp[i-2] + nums[i], dp[i-1]);
        }
        
        return dp[dp.Length-1];
    }
}