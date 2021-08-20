/***************************************
 * Maximize Distance to Closest Person *
 ***************************************/

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int len = seats.size();
        int left = -1;
        int right = 0;        
        int temp1;        
        int ans = 0;
        
        //모든 벡터 순회
        //seats[i] == 0인 값을 기준으로 왼쪽으로 가장 가까운 1, 오른쪽으로 가장 가까운 1을 찾고
        //각 인덱스와 i와의 거리를 구해서 더 작은 거리를 구한다
        for(int i=0; i<len; i++){
            //사람이 앉아있는 자리 기억
            if(seats[i] == 1){
                left = i;
            }
            else{
                //현재 인덱스보다 뒤에있는 인덱스 중에 사람이 앉아있는 자리까지 진행
                while((right < len && seats[right] == 0) || right < i ){
                    right++;
                }

                //현재 인덱스를 기준으로 왼쪽에 사람이 앉은 자리가 없으면
                if(left == -1){
                    //최대값으로 설정해서 최소값에 영향을 주지 않도록 한다
                    temp1 = INT_MAX;
                }
                //현재 인덱스를 기준으로 왼쪽에 사람이 앉은 자리가 있으면
                else{
                    //거리 측정
                    temp1 = i - left;
                }
                
                //위 left의 경우와 같음
                if(right == len){
                    //미리 min연산
                    temp1 = min(temp1, INT_MAX);
                }
                else{
                    temp1 = min(temp1, right - i);
                }
                
                ans = max(ans, temp1);
            }
        }
        
        return ans;
    }
};