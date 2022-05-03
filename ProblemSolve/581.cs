/*****************************************
 * Shortest Unsorted Continuous Subarray *
 *****************************************/

public class Solution {
    public int FindUnsortedSubarray(int[] nums) {
        int minimum = Int32.MaxValue;
        int maximum = Int32.MinValue;
        
        bool flag = false;
        int len = nums.Length;
        
        for(int i=1; i<len; ++i){
            if(nums[i-1] > nums[i]){
                flag = true;
            }
            
            if(flag){
                minimum = Math.Min(minimum, nums[i]);
            }
        }
        
        flag = false;
        
        for(int i=len - 2; i >=0; --i){
            if(nums[i+1] < nums[i]){
                flag = true;
            }
            
            if(flag){
                maximum = Math.Max(maximum, nums[i]);
            }
        }
        
        int left, right;
        
        for(left = 0; left < len; ++left){
            if(minimum < nums[left]){
                break;
            }
        }
        
        for(right = len - 1; right >= 0; --right){
            if(maximum > nums[right]){
                break;
            }
        }
        
        return (right - left < 0) ? 0 : (right - left + 1);
    }
}