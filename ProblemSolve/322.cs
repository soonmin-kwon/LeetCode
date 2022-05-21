/***************
 * Coin Change *
 ***************/


public class Solution {
    public int CoinChange(int[] coins, int amount) {
        int[] cost = new int[amount + 1];
        
        for(int i=0; i<cost.Length; ++i){
            cost[i] = 10001;
        }
        
        cost[0] = 0;
        
        for(int i=0; i<coins.Length; ++i){
            for(int j=coins[i]; j<=amount; ++j){
                cost[j] = Math.Min(cost[j], cost[j-coins[i]] + 1);
            }
        }
        
        return cost[amount] == 10001 ? -1 : cost[amount];
    }
}