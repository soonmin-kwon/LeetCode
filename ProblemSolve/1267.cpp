/**********************************
 * Count Servers that Communicate *
 **********************************/

class Solution {
public:
    //DFS로 grid 탐색
    //같은 row거나 col에 있으면 communicate가능한 server이다
    void dfs(vector<vector<int>>& grid, int r, int c, int& count){
        //같은 row에 있는지 확인
        for(int i=0; i<grid.size(); i++){
            if(grid[i][c]){                
                grid[i][c] = 0;     //중복 방지
                count++;                    
                dfs(grid, i, c, count);
            }
        }
        
        //같은 col에 있는지 확인
        for(int i=0; i<grid[0].size(); i++){
            if(grid[r][i]){
                grid[r][i] = 0;     //중복 방지
                count++;                
                dfs(grid, r, i, count);
            }
        }
        
        return;
    }
    
    int countServers(vector<vector<int>>& grid) {
        int ans = 0;
        int count = 1;
        
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]){
                    grid[i][j] = 0;     //중복 방지
                    count = 1;          //count값 초기화
                    dfs(grid, i, j, count);
                    
                    //이 server를 제외하고 나머지 server가 있으면 count >= 2이다
                    if(count >= 2){     
                        ans += count;
                    }                    
                }
            }
        }
        
        return ans;
    }
};