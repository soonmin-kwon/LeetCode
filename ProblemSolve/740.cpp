/*******************
 * Delete and Earn *
 *******************/

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> prefix(10001);
        vector<int> dp(10001);
        
        int len = nums.size();
        
        //각 element의 값을 미리 더해놓는다
        for(auto x : nums){
            prefix[x] += x;
        }
        
        dp[1] = prefix[1];
        dp[2] = max(prefix[1], prefix[2]);
                
        for(int i=3; i<10001; i++){
            //만약 i를 선택했으면 i - 1, i + 1을 선택하면 안 되기 때문에 점화식을 아래처럼 세운다
            dp[i] = max(dp[i-2] + prefix[i], dp[i-1]);
        }
        
        return max(dp[10000], dp[9999]);
    }
};