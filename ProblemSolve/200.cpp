/*********************
 * Number of Islands *
 *********************/

class Solution {
public:
    int mX[4] = {1, 0, -1, 0};
    int mY[4] = {0, 1, 0, -1};
    int len;
    int len2;
    
    void patrol(vector<vector<char>>& grid, int y, int x) {
        //현재 값을 바꿔서 중첩해서 순찰하지 않도록 한다
        grid[y][x] = '2';
        
        for(int i=0; i<4; i++){
            int nY = y + mY[i];
            int nX = x + mX[i];
            
            //범위를 넘어가지 않는지 체크
            if(nX < len2 && nX >= 0 && nY < len && nY >= 0) {
                //다음으로 진행하는 칸이 1이여야만 진행
                if(grid[nY][nX] == '1'){
                    patrol(grid, nY, nX);
                }                
            }            
        }
        
        return;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        len = grid.size();
        len2 = grid[0].size();
        int ans = 0;
        
        for(int i=0; i<len; i++){
            for(int j=0; j<len2; j++){
                if(grid[i][j] == '1'){
                    patrol(grid, i, j);
                    ans++;
                }
            }
        }
        
        return ans;
    }
};