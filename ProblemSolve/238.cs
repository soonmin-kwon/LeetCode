/********************************
 * Product of Array Except Self *
 ********************************/

public class Solution {
    //나누기 연산 없이 진행
    public int[] ProductExceptSelf(int[] nums) {
        int len = nums.Length;
        
        int[] prefix = new int[len];
        int[] suffix = new int[len];
        int[] ans = new int[len];
        
        prefix[0] = nums[0];
        suffix[len-1] = 1;
        
        //prefix[i] = nums[0]~nums[i]까지 곱한 값
        //suffix[i] = nums[len-1] ~ nums[i+1]까지 곱한 값
        for(int i=1; i<len; ++i){
            prefix[i] = nums[i] * prefix[i-1];
            suffix[len-i-1] = nums[len-i] * suffix[len-i];
        }
                
        ans[0] = suffix[0];
        //i를 기준으로 prefix[i-1] * suffix[i]를 하면 
        //nums[i]를 제외한 나머지 값들은 전부 곱한 값
        for(int i=1; i<len; ++i){
            ans[i] = prefix[i-1] * suffix[i];
        }
        
        return ans;
    }
}