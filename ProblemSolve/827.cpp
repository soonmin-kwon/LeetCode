/*************************
 * Making A Large Island *
 *************************/

//참고 : https://leetcode.com/problems/making-a-large-island/discuss/127015/C%2B%2B-with-picture-O(n*m)

class Solution {
public:        
    int dfs(vector<vector<int>>& grid, int x, int y, int color, int n){        
        if(x<0 || x>=n || y < 0 || y>=n || grid[x][y] != 1){
            return 0;
        }        
        grid[x][y] = color;
        
        //4방향으로 진행, 현재 칸 +1
        return dfs(grid, x + 1, y, color, n) + dfs(grid, x - 1, y, color, n) + dfs(grid, x, y + 1, color, n) + dfs(grid, x, y - 1, color, n) + 1;
    }
    
    int getColor(vector<vector<int>>& grid, int x, int y, int n){
        if(x<0 || x>=n || y < 0 || y>=n ){
            return 0;
        }
        
        return grid[x][y];
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        vector<int> area(2);
        int color = 2;
        int len = grid.size();
        int ans = 0;        
        
        //먼저 1인 지점에서 연결된 넓이를 구하고 각 부분마다 다르게 표시한다.
        for(int i=0; i<len; i++){
            for(int j=0; j<len; j++){
                if(grid[i][j] == 1){
                    area.push_back(dfs(grid, i, j, color, len));
                    color++;
                }
            }
        }
        
        for(int i=0; i<len; i++){
            for(int j=0; j<len; j++){
                if(grid[i][j] == 0){
                    //같은 영역을 두번 더하지 않도록 set이용, 연결되는 지점의 color 값을 저장
                    unordered_set<int> uS = {getColor(grid, i+1,j,len) , getColor(grid, i-1,j,len) , getColor(grid, i,j-1,len) , getColor(grid, i,j+1,len)};
                    
                    //color 값에 따른 area 값 불러와서 모두 더한다.
                    ans = max(ans, 1 + accumulate(begin(uS), end(uS), 0,
                                            [&](int a, int b) {                                   
                                                return a + area[b];
                                            }));
                }
            }
        }
        
        if(ans == 0){
            return len * len;
        }
        
        return ans;
    }
};