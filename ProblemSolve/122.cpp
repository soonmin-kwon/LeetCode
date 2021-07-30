/**************************************
 * Best Time to Buy and Sell Stock II *
 **************************************/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int profit = 0;
        int chose = prices[0];
        int prev;
        int ans = 0;
        
        for(int i=1; i<len; i++){
            chose = min(chose, prices[i]);
            
            prev = profit;            
            profit = max(profit, prices[i] - chose);
            //가격이 오르면 바로 팔아버리고 다시 산다.
            //오르는 족족 팔아버리면 최대
            if(profit != prev && profit > 0){
                ans += profit;
                profit = 0;
                chose = prices[i];
            }
        }
        
        return ans;
    }
};