/****************************
 * Largest Divisible Subset *
 ****************************/

public class Solution {
    public IList<int> LargestDivisibleSubset(int[] nums) {
        int len = nums.Length;
        //subset이 없거나 자기 자신인 경우
        if(len == 1 || len == 0){
            return nums;
        }
        
        //a < b < c일때, b % a = 0이고 c % b = 0이면, c % a = 0이다.
        //a, b, c모양처럼 만들기 위해 sort
        Array.Sort(nums);
        //dp배열에 nums[i]번까지의 수를 이용해 만들 수 있는 subset의 최대 길이 저장.
        int[] dp = new int[len];
        
        //초기화
        for(int i=0; i<len; ++i){
            dp[i] = 1;
        }
        
        int maximumLen = Int32.MinValue;    //만들어야 하는 subset의 길이
                        
        for(int i=1; i<len; ++i){
            for(int j=i-1; j>=0; --j){
                if(nums[i] % nums[j] == 0){
                    dp[i] = Math.Max(dp[i], dp[j] + 1);
                }
            }
            
            maximumLen = Math.Max(maximumLen, dp[i]);
        }
        
        int[] ans = new int[maximumLen];
        int prevNum = 0;
        int idx = 0;
        
        for(int i=len-1; i>=0; --i){
            //큰 수부터 비교하기 때문에 maximumLen에 맞는 nums[i]를 정답에 추가하면 된다
            //하나가 추가될 때마다 maximumLen을 1씩 줄여서 다음 원소를 찾는다.
            //정답에 추가된 수가 나눠떨어지는 수인지 확인하기 위해 prev 변수를 이용해 저장.
            if((dp[i] == maximumLen) && (prevNum % nums[i] == 0)){
                ans[idx] = nums[i];
                --maximumLen;
                ++idx;
                
                prevNum = nums[i];
            }
        }
        
        return ans;
    }
}