/*****************
 * Spiral Matrix *
 *****************/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int minR = 0, minC = 0;
        int maxR = matrix.size(), maxC = matrix[0].size();
        
        //정답 벡터의 최대 길이
        int counts = maxR * maxC;
        vector<int> ans;
        
        //진행 방향 설정
        int turn = 0;
        
        //정답 벡터의 길이가 만족되지 않은 경우 계속해서 loop을 돈다
        while(counts > 0){
            //4방향을 모두 진행하면 m x n 사각형이 (m - 2) x (n - 2) 사각형이 된다
            
            //현재 점에서 오른쪽으로 진행
            if(turn == 0){
                for(int i=minC; i<maxC - 1; i++){
                    ans.push_back(matrix[minR][i]);
                    counts--;                    
                }
                //오른쪽 한 칸을 줄인다
                maxC--;
                //방향 설정
                turn = 1;
            }
            //현재 점에서 아래쪽으로 진행
            else if(turn == 1){
                for(int i=minR; i<maxR; i++){
                    ans.push_back(matrix[i][maxC]);
                    counts--;
                }
            
                //맨 윗줄, 맨 아랫줄을 줄인다
                minR++;
                maxR--;
                turn = 2;                
            }
            //현재 점에서 왼쪽으로 진행
            else if(turn == 2){
                for(int i=maxC - 1; i>minC; i--){
                    ans.push_back(matrix[maxR][i]);
                    counts--;
                }
                turn = 3;
            }
            //현재 점에서 위쪽으로 진행
            else {
                for(int i=maxR; i>=minR; i--){
                    ans.push_back(matrix[i][minC]);
                    counts--;
                }
                //왼쪽 한 칸을 줄인다
                minC++;
                turn = 0;
            }
        }
        
        return ans;
    }
};