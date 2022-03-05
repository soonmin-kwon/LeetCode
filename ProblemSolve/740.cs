/*******************
 * Delete and Earn *
 *******************/

public class Solution {
    public int DeleteAndEarn(int[] nums) {
        int[] prefix = new int[10001];
        int[] dp = new int[10001];
        
        int len = nums.Length;
        
        foreach(int num in nums){
            prefix[num] += num;
        }
        
        dp[1] = prefix[1];
        dp[2] = Math.Max(prefix[1], prefix[2]);
        
        for(int i=3; i<10001; ++i){
            dp[i] = Math.Max(dp[i-2] + prefix[i], dp[i-1]);
        }
        
        return Math.Max(dp[10000], dp[9999]);
    }
}