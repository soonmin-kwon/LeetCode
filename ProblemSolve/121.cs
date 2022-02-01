/***********************************
 * Best Time to Buy and Sell Stock *
 ***********************************/

public class Solution {
    public int MaxProfit(int[] prices) {
        int ans = 0;
        int buyPrice = 10001;
        
        for(int i=0; i<prices.Length; ++i){            
            buyPrice = Math.Min(prices[i], buyPrice);
            ans = Math.Max(ans, prices[i] - buyPrice);
        }
        
        return ans;
    }
}