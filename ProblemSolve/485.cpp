/************************
 * Max Consecutive Ones *
 ************************/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int count = 0;

        //연속된 1의 개수를 세주고 0이 나오면 1의 개수를 초기화 하고 다시 세기 시작한다
        //0이 등장하면 1의 개수를 정답과 비교해 큰 값만 저장한다.
        for(auto num : nums){
            if(num == 1){
                count++;
            }
            else{
                ans = max(ans, count);
                count = 0;
            }
        }
        
        //마지막 숫자가 1인 경우에는 갱신이 되어있지 않기 때문에 마지막으로 갱신해준다.
        ans = max(ans, count);
        
        return ans;
    }
};