/***************************
 * Richest Customer Wealth *
 ***************************/

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = 0, curSum = 0;
        int len = accounts.size();
        
        for(int i=0; i<len; ++i){
            for(int wealth : accounts[i]){
                curSum += wealth;
            }
            
            ans = max(ans, curSum);
            curSum = 0;
        }
        
        return ans;
    }
};