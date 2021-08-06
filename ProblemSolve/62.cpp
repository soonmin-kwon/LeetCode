/****************
 * Unique Paths *
 ****************/

class Solution {
public:
    int uniquePaths(int m, int n) {        
        //각 칸에 도달하는 모든 경로의 수를 저장
        vector<vector<int>> path(m, vector<int>(n,1));        
        
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                //현재 있는 칸의 위, 옆 칸의 수를 더하면 현재 칸에 도달하는 모든 경로의 수
                path[i][j] = path[i-1][j] + path[i][j-1];
            }
        }
        
        return path[m-1][n-1];
    }
};