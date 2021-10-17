/********************************************
 * Number of Longest Increasing Subsequence *
 ********************************************/

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {        
        vector<int> dp(nums.size(), 1);     //dp[i]는 nums[i]까지 longest increasing subsequence의 길이
        vector<int> count(nums.size(), 1);  //dp[i]가 longest increasing subsequence의 길이를 나타내고 같은 길이를 가지는 subsequence의 개수 저장
        
        int maxLength = 1;
        
        for(int i=1; i<nums.size(); i++){
            for(int j = i - 1; j>=0; j--){
                //increase한지 체크한다
                if(nums[i] > nums[j]){                    
                    //dp[j]는 nums[j]까지의 subsequence의 길이를 나타내기 때문에
                    //nums[i]가 nums[j]보다 큰 상황에서 dp[i]의 값은 dp[j] + 1이 된다
                    //dp[i]값을 최대 값으로 유지해야 longest subsequence의 길이를 구할 수 있다
                    if(dp[j] + 1 > dp[i]){
                        dp[i] = dp[j] + 1;
                        //dp[i]값이 갱신되는 상황이기 때문에 count값도 갱신된다
                        count[i] = count[j];
                    }
                    //dp[i]가 최대값으로 유지되는 상황에서 dp[j] + 1이 dp[i]와 같다는 뜻은
                    //같은 길이를 가지는 subseqeunce가 더 있다는 뜻이다
                    //subsequence의 개수를 count에 저장하기 때문에 count 값을 더해준다
                    else if(dp[j] + 1 == dp[i]){
                        count[i] += count[j];
                    }
                    
                }
            }
            //최대 길이 저장
            maxLength = max(maxLength, dp[i]);
        }
        
        int ans = 0;
        
        for(int i=0; i<nums.size(); i++){
            //최대 길이를 가지는 dp[i] 값이 있다면
            //정답은 count[i]만큼 증가한다
            if(dp[i] == maxLength){
                ans += count[i];
            }
        }
        
        return ans;
    }
};