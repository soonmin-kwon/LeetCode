/**************************************************
 * Final Prices With a Special Discount in a Shop *
 **************************************************/

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int len = prices.size();
        
        vector<int> discount(len);        
        
        //buret force
        for(int i=0; i<len; i++){
            for(int j=i+1; j<len; j++){
                //조건에 맞으면 바로 계산
                if(prices[j] <= prices[i]){
                    prices[i] -= prices[j];
                    break;
                }
            }
        }
        
        return prices;
    }
};