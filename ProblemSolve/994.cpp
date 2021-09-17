/*******************
 * Rotting Oranges *
 *******************/

class Solution {
public:
    int mX[4] = {0, 1, 0, -1};
    int mY[4] = {1, 0, -1, 0};
    
    int orangesRotting(vector<vector<int>>& grid) {
        int remain = 0;
        queue<pair<int,pair<int,int>>> q;
        
        //썩은 오렌지의 위치와 신선한 오렌지의 개수를 센다
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 2){
                    q.push(make_pair(0, make_pair(i, j)));
                }
                else if(grid[i][j] == 1){
                    remain++;
                }
            }
        }
        
        int minute = 0;
        
        //BFS
        while(!q.empty()){
            int y = q.front().second.first;
            int x = q.front().second.second;
            
            //몇 분이 지났는지 체크
            minute = q.front().first;
            
            q.pop();
            
            for(int i=0; i<4; i++){
                int nY = y + mY[i];
                int nX = x + mX[i];
                
                if(nY < 0 || nY >= grid.size() || nX < 0 || nX >= grid[0].size()){
                    continue;
                }
                
                if(grid[nY][nX] == 1){
                    grid[nY][nX] = 2;
                    //신선한 오렌지의 개수를 줄여준다
                    remain--;
                    q.push(make_pair(minute + 1, make_pair(nY, nX)));
                }
            }
        }
        
        //신선한 오렌지의 개수가 남아있으면 -1
        if(remain > 0){
            return -1;
        }
        
        return minute;
    }
};