/********************
 * Maximum Subarray *
 ********************/

public class Solution {
    public int MaxSubArray(int[] nums) {
        //-10000 <= nums[i] <= 10000
        int ans = -10001, tempSubarray = 0;
        
        //Kadane Algorithm
        foreach(int num in nums){
            tempSubarray += num;
            ans = Math.Max(ans, tempSubarray);
            tempSubarray = Math.Max(tempSubarray, 0);
        }
        
        return ans;
    }
}