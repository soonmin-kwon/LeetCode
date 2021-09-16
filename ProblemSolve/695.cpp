/**********************
 * Max Area of Island *
 **********************/

class Solution {
public:    
    int lenY, lenX;     //최대 길이 저장    
    int temp = 0;       //섬의 최대 넓이 임시 저장
    
    void dfs(vector<vector<int>>& grid, int y, int x){
        //범위를 벗어나는 경우 처리
        if(y < 0 || x < 0 || y >= lenY || x >= lenX){
            return;
        }
        
        //섬의 면적이 아닌 경우 처리
        if(grid[y][x] == 0){
            return;
        }
        
        //섬의 면적인 경우
        if(grid[y][x]){
            //방문했다는 걸 표시하기 위해 0으로 바꾸고
            grid[y][x] = 0;
            //면적을 센다
            temp++;
        }
        
        //4방향으로 진행
        dfs(grid, y + 1, x);
        dfs(grid, y - 1, x);
        dfs(grid, y, x + 1);
        dfs(grid, y, x - 1);
        
        return;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        lenY = grid.size();
        lenX = grid[0].size();
        int ans = 0;
        
        for(int i=0; i<lenY; i++){
            for(int j=0; j<lenX; j++){
                //섬의 면적인 경우 dfs 진행
                if(grid[i][j]){
                    dfs(grid, i, j);
                    //최대값 지속 갱신
                    ans = max(ans, temp);
                    //temp 값 초기화
                    temp = 0;
                }
            }
        }
        
        return ans;
    }
};