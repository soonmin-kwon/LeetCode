/*********************
 * Pascal's Triangle *
 *********************/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        ans[0].push_back(1);
        
        //한 줄이면 바로 리턴
        if(numRows == 1){
            return ans;
        }
                
        ans[1].push_back(1);
        ans[1].push_back(1);
        
        for(int i=2; i<numRows; i++){
            for(int j=0; j<= i; j++){
                if(j == 0 || j == i){
                    //양쪽 끝이면 
                    ans[i].push_back(1);
                }
                else{
                    //바로 위, 왼쪽 위 칸 더하기
                    ans[i].push_back(ans[i-1][j-1] + ans[i-1][j]);
                }
            }
        }
        
        return ans;
    }
};