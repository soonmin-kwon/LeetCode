/*********************
 * Arithmetic Slices *
 *********************/

//참고 : https://leetcode.com/problems/arithmetic-slices/discuss/90093/3ms-C%2B%2B-Standard-DP-Solution-with-Very-Detailed-Explanation

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int len = nums.size();
        
        if(len < 3){
            return 0;
        }
        
        vector<int> dp(len);
        int ans = 0;        

        for(int i=2; i<len; i++){
            //arithmetic한지 확인
            if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2]){
                //dp[i]는 nums[i]까지의 arithmetic한 slice의 개수
                //nums[i-1]까지가 이미 arithmetic하다면 nums[i]까지의 arithmetic한 slice의 개수는
                //이전까지도 arithmetic하기 때문에 하나가 추가된 길이의 arithmetic한 slice + 위에서 arithmetic한지 확인한 개수
                dp[i] = dp[i-1] + 1;
            }
            
            ans += dp[i];
        }
        
        return ans;
    }
};