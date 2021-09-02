/*******************
 * House Robber II *
 *******************/

class Solution {
public:
    int rob(vector<int>& nums) {
        //굳이 다른 연산이 필요 없는 경우들
        if(nums.size() == 0){
            return 0;
        }
        else if(nums.size() == 1){
            return nums[0];
        }
        else if(nums.size() == 2){
            return max(nums[0], nums[1]);
        }
        
        int len = nums.size();
        int temp;
        vector<int> dp(len);
        
        //첫번째 element를 훔치는 경우
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        //첫번째 element를 훔치는 경우에는 마지막 element를 훔칠 수 없다
        for(int i=2; i<len - 1; i++){
            //현재 집을 훔치면 이전 집은 훔칠 수 없고, 최대 값을 훔쳐야하므로 현재 집을 훔치지않는 것이 더 많이 훔칠 수 있는지 확인
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        }
        
        temp = dp[len-2];
        
        //두번째 element부터 훔치는 경우
        dp[0] = nums[1];
        dp[1] = max(nums[1], nums[2]);
        
        //두번째 element부터 훔치는 경우에는 마지막 element를 훔칠 수 있다
        for(int i=3; i<len; i++){
            dp[i-1] = max(dp[i-3] + nums[i], dp[i-2]);
        }
        
        return max(temp, dp[len-2]);
    }
};