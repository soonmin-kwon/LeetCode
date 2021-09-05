/****************************
 * Minimum Falling Path Sum *
 ****************************/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int len = matrix.size();
        
        //두번째 row부터 확인
        for(int i=1; i<len; i++){
            //모든 col 확인
            for(int j=0; j<len; j++){
                //왼쪽 끝 element이면 위, 오른위 확인
                if(j == 0){
                    matrix[i][j] += min(matrix[i-1][j], matrix[i-1][j+1]);
                }
                //오른쪽 끝 element이면 위, 왼쪽위 확인
                else if(j == len-1){
                    matrix[i][j] += min(matrix[i-1][j], matrix[i-1][j-1]);
                }
                //그 외에는 왼쪽위, 위, 오른쪽위 확인
                else{
                    matrix[i][j] += min(matrix[i-1][j-1], min(matrix[i-1][j], matrix[i-1][j+1]));
                }
            }
        }
        
        int ans = INT_MAX;
        
        //마지막 row에 있는 모든 값중에 가장 작은 값 저장
        for(int i=0; i<len; i++){
            ans = min(matrix[len-1][i], ans);
        }
        
        return ans;
    }
};