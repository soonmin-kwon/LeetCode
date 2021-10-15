/***********************
 * Matrix Diagonal Sum *
 ***********************/

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int left = 0, right = mat.size() - 1;
        int ans = 0;
        
        //맨 윗줄부터 맨 아랫줄까지 진행하면서
        //대각선 위치의 값들을 더해준다
        //홀수길이 mat의 경우 두번 더해지는 경우가 있어 빼준다
        for(int i=0; i<mat.size(); i++){
            if(left == right){
                ans -= mat[i][left];
            }
            
            ans += mat[i][left++] + mat[i][right--];
        }
        
        return ans;
    }
};