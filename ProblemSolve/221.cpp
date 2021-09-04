/******************
 * Maximal Square *
 ******************/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int len = matrix.size();
        int len2 = matrix[0].size();        
        int ans = 0;
        vector<vector<int>> dp(len + 1, vector<int>(len2 + 1, 0));
        
        for(int i=1; i<=len; i++){
            for(int j=1; j<=len2; j++){
                if(matrix[i-1][j-1] == '1'){                    
                    //dp[i][j]는 (i,j)를 우측 하단 꼭지점으로하는 정사각형의 변의 길이를 나타낸다
                    //왼쪽칸, 왼쪽위칸, 위칸을 비교하면서 가능한 사각형의 크기를 설정
                    dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1])) + 1;
                }                
                
                //가능한 정사각형의 가장 큰 변의 길이를 저장
                ans = max(ans, dp[i][j]);                
            }
        }
        
        return ans * ans;
    }
};