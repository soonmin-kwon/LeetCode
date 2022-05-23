/******************
 * One and Zeroes *
 ******************/

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n+1,0));
        
        int zeroCount = 0, oneCount = 0;
        
        for(int i=0; i<strs.size(); ++i){
            int zeroCount = count(strs[i].begin(), strs[i].end(), '0');
            int oneCount = strs[i].size() - zeroCount;
            
            for(int j = m; j >= zeroCount; --j){
                for(int k = n; k >= oneCount; --k){
                    dp[j][k] = max(dp[j][k], dp[j - zeroCount][k - oneCount] + 1);
                }
            }
        }
        
        return dp[m][n];
    }
};