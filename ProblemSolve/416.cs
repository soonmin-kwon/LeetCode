/******************************
 * Partition Equal Subset Sum *
 ******************************/

//참고 : https://leetcode.com/problems/partition-equal-subset-sum/discuss/950659/C%2B%2B-Simple-Dynamic-Programming-Explained-Solution

public class Solution {
    public bool CanPartition(int[] nums) {
        int sum = 0;
        
        foreach(int num in nums){
            sum += num;
        }
        
        if(sum % 2 != 0){
            return false;
        }
        
        sum /= 2;
        
        bool[] dp = new bool[sum + 1];
        
        dp[0] = true;
        
        foreach(int num in nums){
            for(int i=sum; i>=num; --i){
                dp[i] = dp[i] || dp[i-num];
            }
        }
        
        return dp[sum];
    }
}