/***********************************
 * Best Time to Buy and Sell Stock *
 ***********************************/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int profit = 0;
        int chose = 10001;
        
        //최저점을 갱신하면서 최저점에 따른 최고수익을 계산
        for(int i=0; i<len; i++){
            chose = min(chose, prices[i]);
            profit = max(profit, prices[i] - chose);
        }
        
        return profit;        
    }
};