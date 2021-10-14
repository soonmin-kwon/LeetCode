/*********************
 * Count Sub Islands *
 *********************/

class Solution {
public:
    int maxRow, maxCol;
    
    //4방향으로 그래프를 탐색하면서 sub island인지 확인한다
    //* 으로 계산하면서 한 칸이라도 sub island조건에 맞지 않으면 0이 return 된다
    int dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int r, int c){
        int temp = 1;
        
        //처음에 1에서 dfs가 시작되기 때문에 범위 밖에 있거나 0으로 도착하면 island의 조건을 만족한다
        //1이 계속 return되어도 *으로 계산하기 때문에 상관이 없다
        if(r < 0 || c < 0 || r >= maxRow || c >= maxCol || grid2[r][c] == 0){
            return 1;
        }
        
        //visitied 배열 대신 0으로 바꿔서 사용한다
        grid2[r][c] = 0;
        temp *= dfs(grid1, grid2, r + 1, c);
        temp *= dfs(grid1, grid2, r - 1, c);
        temp *= dfs(grid1, grid2, r, c + 1);
        temp *= dfs(grid1, grid2, r, c - 1);
        
        //grid1[r][c]가 0이면 sub island가 될 수 없다
        return temp * grid1[r][c];
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        maxRow = grid1.size();
        maxCol = grid1[0].size();
        int ans = 0;
        
        for(int i=0; i<maxRow; i++){
            for(int j=0; j<maxCol; j++){
                if(grid2[i][j]){
                    ans += dfs(grid1, grid2, i, j);
                }
            }
        }
        
        return ans;
    }
};