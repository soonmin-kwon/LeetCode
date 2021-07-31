/****************
 * Rotate Image *
 ****************/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int len = matrix.size();
        
        // 대각선을 중심으로 swap해준다.
        for(int i=0; i<len; i++){
            for(int j=i; j<len; j++){                
                if(i != j){
                    swap(matrix[i][j], matrix[j][i]);
                }                                
            }
        }
        
        // 각 줄마다 거꾸로 돌리면 90도 회전이 된다.
        for(int i=0; i<len; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};