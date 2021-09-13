/*************************************
 * Max Increase to Keep City Skyline *
 *************************************/

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 0;
        
        //row, col을 기준으로 가장 큰 값을 저장
        //maxRowHeight[0] = max({grid[0][0], grid[0][1], grid[0][2], grid[0][3] ... });
        vector<int> maxRowHeight(n);    
        
        //maxColHeight[0] = max({grid[0][0], grid[1][0], grid[2][0], grid[3][0] ... });
        vector<int> maxColHeight(n);
        
        for(int i=0; i<n; i++){
            maxRowHeight[i] = *max_element(grid[i].begin(), grid[i].end());
            
            for(int j=0; j<n; j++){
                maxColHeight[i] = max(maxColHeight[i], grid[j][i]);
            }            
        }
        
        //한 지점을 동, 서, 남 북에서 보기 때문에 maxColHeight와 maxRowHeight 값을 잘 고려해서 선택해야 한다
        //maxColHeight 값이 maxRowHeight 값보다 큰 경우에 maxColHeight 값을 택하게 되면 skyline이 바뀌게 된다
        //반대로 maxRowHeight 값이 maxColHeight 값보다 큰 경우에도 마찬가지이다
        //따라서 두 값중 더 작은 값을 택하게 되면 skyline이 변하지 않게 건물의 높이를 최대한으로 키우는 경우가 된다        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                //원래 건물과의 차이만을 계산
                ans += min(maxRowHeight[i], maxColHeight[j]) - grid[i][j];                
            }
        }
        
        return ans;
    }
};