/****************************
 * Largest Divisible Subset *
 ****************************/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int len = nums.size();
        
        if(len == 1 || len == 0){
            return nums;
        }
        
        //오름차순으로 정렬해 작은 수로 큰 수가 나눠지는지 확인할때 용이하도록 한다
        sort(nums.begin(), nums.end());
        //자기 자신으로 나눠지므로 1로 초기화
        //dp[i] = nums[i]를 나눠 떨어지게 할 수 있는 숫자의 개수
        vector<int> dp(len, 1);
        int maximum = INT_MIN;
        
        //현재 값보다 작은 값들을 찾으면서 나눠떨어지는지 확인하고
        //나눠떨어지면 나누는 수의 dp 값을 찾아 1을 더한다.
        //현재 값이 b고 나누려는 값이 a라고 했을때 a가 c와 d로 나눠떨어지면 b 역시 c와 d로 나눠떨어진다
        //dp배열에 나눠떨어지는 수의 개수를 저장하므로 dp값을 이용해 현재 값이 몇개의 수로 나눠떨어지는지 계산한다
        //ex) nums = [1, 2, 4], dp = [1, 2, 3]
        for(int i=1; i<len; i++){
            for(int j=i-1; j>=0; j--){
                if(nums[i] % nums[j] == 0){                    
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            //정답 배열의 길이
            maximum = max(maximum, dp[i]);
        }
        
        vector<int> ans;
        //prev 값을 이용해 dp[i]의 값이 같아도 나눠떨어지는 수만 확인한다
        int prev = 0;
        
        for(int i=len-1; i>=0; i--){
            if((dp[i] == maximum) && (prev % nums[i] == 0)){
                ans.push_back(nums[i]);                
                maximum--;
                //정답 배열에 들어간 수를 기준으로 나눠떨어져야 정답이 된다.
                //정답 배열에는 큰 수부터 들어가기때문에 더 작은 수를 나눌 수 있는 수만 찾으면 된다
                prev = ans.back();
            }
        }
        
        return ans;
    }
};