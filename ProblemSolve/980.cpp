/********************
 * Unique Paths III *
 ********************/

class Solution {
public:
    int lenR, lenC;             //m, n -> row의 길이, column의 길이
    int walkCount = 0;          //움직여야하는 칸의 개수
    
    //DFS 방식, 한 칸씩 grid 위를 움직이면서 ending square에 도착하는지 확인
    //범위를 벗어나거나 장애물을 만나면 return
    //다시 돌아오는 경우를 방지하기 위해 이미 지나간 곳을 장애물로 설정 -> Backtracking
    void backtracking(vector<vector<int>>& grid, int r, int c, int curCount, int& ans){
        //범위를 벗어나거나 장애물을 만난 경우
        if(r < 0 || r >= lenR || c < 0 || c >= lenC || grid[r][c] == -1){
            return;
        }
        
        do{
            if(grid[r][c] == 2){
                if(curCount == walkCount){
                    ans += 1;
                }   
                return;
            }
        }while(false);
        
        //Backtracking
        grid[r][c] = -1;
        
        backtracking(grid, r + 1, c, curCount + 1, ans);
        backtracking(grid, r - 1, c, curCount + 1, ans);
        backtracking(grid, r, c + 1, curCount + 1, ans);
        backtracking(grid, r, c - 1, curCount + 1, ans);
        
        grid[r][c] = 0;
        
        return;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        lenR = grid.size();
        lenC = grid[0].size();
        
        int startXPos, startYPos;
        int ans = 0;
        
        for(int i=0; i<lenR; i++){
            for(int j=0; j<lenC; j++){
                //시작 위치 설정
                if(grid[i][j] == 1){
                    startYPos = i;
                    startXPos = j;                    
                }
                //움직여야하는 칸의 개수를 센다
                //grid[i][j] == 2여도 그 칸까지 움직여야하므로
                //grid[i][j] == 2, grid[i][j] == 0의 개수를 센다
                else if(grid[i][j] != -1){
                    walkCount++;
                }
            }
        }
        
        backtracking(grid, startYPos, startXPos, 0, ans);    
        
        return ans;
    }
};