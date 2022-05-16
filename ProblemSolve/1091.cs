/**********************************
 * Shortest Path in Binary Matrix *
 **********************************/
  
public class Solution {
    public int[] moveX = new int[8] {-1, -1, -1, 0, 0, 1, 1, 1};
    public int[] moveY = new int[8] {-1, 0, 1, -1, 1, -1, 0, 1};
    
    public struct Position{
        public int x;
        public int y;
        
        public Position(int x, int y){
            this.x = x;
            this.y = y;
        }
    }
    
    public int ShortestPathBinaryMatrix(int[][] grid) {
        int row = grid.Length;
        int col = grid[0].Length;
        int ans = 1;
        
        if(grid[0][0] == 1 || grid[row - 1][col - 1] == 1){
            return -1;
        }
        
        Queue<Position> queue = new Queue<Position>();
        queue.Enqueue(new Position(0,0));
        grid[0][0] = 1;
        
        while(queue.Count > 0){
            Position curPos = queue.Dequeue();
            
            int x = curPos.x;
            int y = curPos.y;
            
            if(y == row - 1 && x == col - 1){
                return grid[y][x];
            }
            
            for(int i=0; i<8; ++i){
                int nextX = x + moveX[i];
                int nextY = y + moveY[i];
                
                if(0 <= nextX && nextX < col && 0 <= nextY && nextY < row && grid[nextY][nextX] == 0){
                    queue.Enqueue(new Position(nextX, nextY));
                    grid[nextY][nextX] = grid[y][x] + 1;
                }
            }
        }
        
        return -1;
    }
}