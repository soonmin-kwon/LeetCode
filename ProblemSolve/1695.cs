/*************************
 * Maximum Erasure Value *
 *************************/

public class Solution {
    public int MaximumUniqueSubarray(int[] nums) {
        int[] hash = new int[10001];
        int ans = 0;
        int left = 0;
        int right = 0;
        int curSum = 0;
        
        while(right < nums.Length){
            hash[nums[right]]++;
            curSum += nums[right];
            
            while(hash[nums[right]] > 1){
                hash[nums[left]]--;
                curSum -= nums[left];
                left++;
            }
            
            ans = Math.Max(ans, curSum);
            right++;
        }
        
        return ans;
    }
}