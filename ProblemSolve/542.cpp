/*************
 * 01 Matrix *
 *************/

class Solution {
public:
    int mX[4] = {1, 0, -1, 0};
    int mY[4] = {0, 1, 0, -1};
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> ans(mat.size(), vector<int>(mat[0].size(), INT_MAX));
        
        queue<pair<int,int>> q;
        
        //0인 곳은 거리를 0으로 바꿔주고 1인 곳의 위치를 기억한다
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat[0].size(); j++){
                if(mat[i][j] == 0){
                    ans[i][j] = 0;
                    q.push(make_pair(i, j));
                }
            }
        }
        
        pair<int,int> temp;
        
        while(!q.empty()){
            temp = q.front();
            q.pop();
            
            for(int i=0; i<4; i++){
                int nY = temp.first + mY[i];
                int nX = temp.second + mX[i];
                
                if(nY < 0 || nY >= mat.size() || nX < 0 || nX >= mat[0].size()){
                    continue;                    
                }
                
                //다음 점으로 진행할 때 그 점에 도착할 수 있는 최소 거리를 저장한다
                if(ans[nY][nX] > ans[temp.first][temp.second] + 1){
                    ans[nY][nX] = ans[temp.first][temp.second] + 1;
                    q.push(make_pair(nY, nX));
                }
            }
        }
        
        return ans;
    }
};