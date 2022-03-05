/*******************
 * Champagne Tower *
 *******************/

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double dp[102][102] = {0.0, };
        
        dp[0][0] = (double)poured;
        
        for(int row = 0; row<=query_row; ++row){
            for(int col = 0; col<=row; ++col){
                double quantity = (dp[row][col] - 1.0) / 2.0;
                
                if(quantity > 0){
                    dp[row+1][col] += quantity;
                    dp[row+1][col+1] += quantity;
                }
            }
        }

        return min(1.0, dp[query_row][query_glass]);
    }
};