/*************************************
 * Search in Rotated Sorted Array II *
 *************************************/

public class Solution {
    public bool Search(int[] nums, int target) {
        int left = 0, right = nums.Length - 1;
        
        while(left <= right){
            while(left < right && nums[left] == nums[left + 1]){
                left++;
            }
            
            while(left < right && nums[right] == nums[right - 1]){
                right--;
            }
            
            int mid = (right + left) / 2;
            
            if(nums[mid] == target){
                return true;
            }
            else if(nums[mid] >= nums[left]){
                if(nums[left] <= target && nums[mid] >= target){
                    right = mid - 1;
                }
                else{
                    left = mid + 1;
                }
            }
            else{
                if(nums[mid] <= target && nums[right] >= target){
                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                }
            }
        }
        
        return false;
    }
}