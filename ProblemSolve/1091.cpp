/**********************************
 * Shortest Path in Binary Matrix *
 **********************************/

class Solution {
public:
    int moveX[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int moveY[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int ans = 1;
        
        if(grid[0][0] == 1 || grid[row - 1][col - 1] == 1){
            return -1;
        }
        queue<pair<int, int>> queue;
        queue.push(make_pair(0,0));
        grid[0][0] = 1;
        
        while(!queue.empty()){
            pair<int, int> curPos = queue.front();
            queue.pop();
            
            int x = curPos.second;
            int y = curPos.first;
            
            if(y == row - 1 && x == col - 1){
                return grid[y][x];
            }
            
            for(int i=0; i<8; ++i){
                int nextY = y + moveY[i];
                int nextX = x + moveX[i];
                
                if(nextY >= 0 && nextY < row && nextX >=0 && nextX < col && grid[nextY][nextX] == 0){
                    queue.push(make_pair(nextY, nextX));
                    grid[nextY][nextX] = grid[y][x] + 1;
                }
            }
        }
        
        return -1;
    }
};