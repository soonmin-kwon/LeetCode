/**************************************
 * Best Time to Buy and Sell Stock II *
 **************************************/

public class Solution {
    public int MaxProfit(int[] prices) {
        int len = prices.Length;
        
        int buyPrice = prices[0];
        int ans = 0;
        
        //오르는 족족 팔아버리면 최대 이윤을 얻을 수 있다.
        //싸게 사서 비싸게 팔면 된다.
        for(int i=1; i<len; i++){
            buyPrice = Math.Min(buyPrice, prices[i]);
                        
            //이윤이 생기는지 확인
            if(prices[i] - buyPrice > 0){
                ans += (prices[i] - buyPrice);
                buyPrice = prices[i];
            }
        }
        
        return ans;
    }
}