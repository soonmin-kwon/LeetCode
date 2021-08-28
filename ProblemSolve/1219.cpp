/**************************
 * Path with Maximum Gold *
 **************************/

class Solution {
public:
    int dfs(vector<vector<int>>& grid, int x, int y){
        //범위를 벗어나거나 조건에 맞지 않으면 return 0
        if(x < 0 || x >= grid[0].size() || y < 0 || y >= grid.size() || grid[y][x] == 0){
            return 0;
        }
        
        //값 저장
        int temp = grid[y][x];
        int ans = 0;
        //다시 못 돌아오게 0으로 바꾼다
        grid[y][x] = 0;
        
        ans = max(ans, dfs(grid, x + 1, y));    //right
        ans = max(ans, dfs(grid, x - 1, y));    //left
        ans = max(ans, dfs(grid, x, y + 1));    //down
        ans = max(ans, dfs(grid, x, y - 1));    //up
        
        //원상복구
        grid[y][x] = temp;
        
        return ans + temp;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int ans = 0;
        int len = grid.size();
        int len2 = grid[0].size();
        
        for(int i=0; i<len; i++){
            for(int j=0; j<len2; j++){
                //grid[i][j]가 0이 아닌 경우에만 탐색 시작
                if(grid[i][j]){
                    ans = max(ans, dfs(grid, j, i));
                }
            }
        }
        
        return ans;
    }
};