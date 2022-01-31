/***************************
 * Richest Customer Wealth *
 ***************************/

public class Solution {
    public int MaximumWealth(int[][] accounts) {
        int ans = 0;
        int curSum = 0;
        
        for(int i=0; i<accounts.Length; ++i){
            foreach(int wealth in accounts[i]){
                curSum += wealth;
            }
            
            ans = Math.Max(ans, curSum);
            curSum = 0;
        }
        
        return ans;
    }
}