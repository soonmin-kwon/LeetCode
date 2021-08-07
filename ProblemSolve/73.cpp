/*********************
 * Set Matrix Zeroes *
 *********************/

class Solution {
public:    
    //O(m + n) Space
    void setZeroes(vector<vector<int>>& matrix) {
        int len = matrix.size();
        int len2 = matrix[0].size();
        
        //0이 있는 좌표 저장
        queue<pair<int,int>> q;
                
        for(int i=0; i<len; i++){
            for(int j=0; j<len2; j++){
                if(matrix[i][j] == 0){
                    q.push(make_pair(i,j));
                }
            }
        }
        
        //위에서 저장한 좌표들을 찾아서 row,col을 0으로 만든다.
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(int i=0; i<len2; i++){
                matrix[row][i] = 0;
            }
            
            for(int i=0; i<len; i++){
                matrix[i][col] = 0;
            }
        }
        
        return;
    }
    
    //Solution, O(1) Space
    void setZeroes(vector<vector<int>>& matrix) {
        int len = matrix.size();
        int len2 = matrix[0].size();
        
        //첫 row, col인지 체크
        bool firstRow = false;
        bool firstCol = false;
        
        //전체 matrix를 돌면서 0이면 그 0이 있는 row, col의 맨 앞에 체크
        for(int i=0; i<len; i++) {
            for(int j=0; j<len2; j++) {
                if(matrix[i][j] == 0){
                    if(i == 0){
                        firstRow = true;
                    }
                    
                    if(j == 0){
                        firstCol = true;
                    }
                    
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        
        //row, col의 맨 앞에 체크해뒀기 때문에 그 다음 줄 부터 돌면서 맨 앞이 0인지 확인 후 0으로 변환
        for(int i=1; i<len; i++) {
            for(int j=1; j<len2; j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        
        //0, x가 0이면 그 col을 0으로
        if(firstRow){
            for(int i=0; i<len2; i++){
                matrix[0][i] = 0;
            }
        }
        
        //x, 0이 0이면 그 row를 0으로
        if(firstCol){
            for(int i=0; i<len; i++){
                matrix[i][0] = 0;
            }
        }
        
        return;
    }
};