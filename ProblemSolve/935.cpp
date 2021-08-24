/*****************
 * Knight Dialer *
 *****************/

#define mod 1000000007

class Solution {
public:
    int knightDialer(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(10));        
        
        //기초작업
        for(int i=0; i<10; i++){
            dp[1][i] = 1;
        }
        
        //dp[i][j]라 가정했을때, j점에서 도착할 수 있는 모든 점에대해 가능한 가지수를 더한다
        for(int i=2; i<=n; i++){                            
            dp[i][0] = (dp[i-1][4] + dp[i-1][6]) % mod;
            dp[i][1] = (dp[i-1][8] + dp[i-1][6]) % mod;
            dp[i][2] = (dp[i-1][7] + dp[i-1][9]) % mod;
            dp[i][3] = (dp[i-1][4] + dp[i-1][8]) % mod;
            dp[i][4] = ((dp[i-1][3] + dp[i-1][9]) % mod + dp[i-1][0])% mod;
            dp[i][6] = ((dp[i-1][1] + dp[i-1][7]) % mod + dp[i-1][0]) % mod;
            dp[i][7] = (dp[i-1][2] + dp[i-1][6]) % mod;
            dp[i][8] = (dp[i-1][1] + dp[i-1][3]) % mod;                        
            dp[i][9] = (dp[i-1][4] + dp[i-1][2]) % mod;
        }     
        int ans = 0;
        
        for(int i=0; i<10; i++){
            ans = (ans + dp[n][i]) % mod;
        }
        
        return ans;
    }
};