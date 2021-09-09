/***************************************
 * Longest Increasing Path in a Matrix *
 ***************************************/

class Solution {
public:
    int mX[4] = {1, 0, -1, 0};
    int mY[4] = {0, 1, 0, -1};
    int len, len2;
    
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int y, int x){
        //이미 가능한 최대 거리가 계산된 경우 리턴
        if(dp[y][x] != 1){
            return dp[y][x];
        }                
        
        for(int i=0; i<4; i++){
            //가능한 좌표 탐색
            int nX = x + mX[i];
            int nY = y + mY[i];
            
            //범위에서 벗어나는 좌표나, 조건에 부합하지 않으면 탐색하지 않는다
            if(nY < 0 || nY >= len || nX < 0 || nX >= len2 || matrix[nY][nX] <= matrix[y][x]){
                continue;
            }
            
            //현재 칸에서 가능한 경로를 탐색, 최대 거리만 저장하면서 진행
            dp[y][x] = max(dp[y][x], 1 + dfs(matrix, dp, nY, nX));
        }
                          
        return dp[y][x];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        len = matrix.size();
        len2 = matrix[0].size();
        int ans = 0;        
        //자기 자신을 탐색할 수 있기 때문에 1로 초기화
        vector<vector<int>> dp(len, vector<int>(len2, 1));
        
        for(int i=0; i<len; i++){
            for(int j=0; j<len2; j++){
                //모든 좌표에서 경로 탐색
                ans = max(ans, dfs(matrix, dp, i, j));
            }
        }
        return ans;
    }
};