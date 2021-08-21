/********************
 * Matrix Block Sum *
 ********************/

//참고 : https://leetcode.com/problems/matrix-block-sum/discuss/549010/C%2B%2B-oror-64.38-time-oror-100.00-space-oror-graph-illustration

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {        
        int len = mat.size();
        int len2 = mat[0].size();
        vector<vector<int>> prefixSum(len + 1, vector<int>(len2 + 1, 0));
        vector<vector<int>> ans(len, vector<int>(len2, 0));
        
        for(int i=1; i<=len; i++){
            for(int j=1; j<=len2; j++){
                //두번 더한 원소를 빼주면서 prefixSum을 구한다
                prefixSum[i][j] = prefixSum[i-1][j] + prefixSum[i][j-1] - prefixSum[i-1][j-1] + mat[i-1][j-1];
            }
        }
                
        for(int i=0; i<len; i++){
            for(int j=0; j<len2; j++){
                //범위를 넘어가는지 확인
                int r1 = max(0, i - k) + 1; //row 시작점
                int r2 = min(i + k + 1, len); //row 끝점
                
                int c1 = max(0, j - k) + 1; //col 시작점
                int c2 = min(j + k + 1 , len2); //col 끝점
                
                //k = 1
                //prefixSum은 1,1부터 시작
                //ans[2][2] = prefixSum[3][3] - prefixSum[1][3] - prefixSum[3][1] + prefix_sum[1][1]
                ans[i][j] = prefixSum[r2][c2] - prefixSum[r1-1][c2] - prefixSum[r2][c1-1] + prefixSum[r1-1][c1-1];
            }
        }
        
        return ans;
    }
};