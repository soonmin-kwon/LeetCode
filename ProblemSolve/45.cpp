/****************
 * Jump Game II *
 ****************/

class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0;
        int len = nums.size();
        
        //배열 초기화
        vector<int> dp(len, 10000001);
        
        dp[0] = 0;
        
        //각 지점에서 갈 수 있는 모든 지점에 배열 값을 초기화
        for(int i=0; i<len; i++){            
            for(int j = i + 1; j<= i + nums[i] && j < len; j++){
                dp[j] = min(dp[j], dp[i] + 1);
            }
        }
        
        return dp[len-1];
    }
};