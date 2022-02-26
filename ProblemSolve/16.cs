/****************
 * 3Sum Closest *
 ****************/

public class Solution {
    public int ThreeSumClosest(int[] nums, int target) {
        Array.Sort(nums);
        int closest = nums[0] + nums[1] + nums[nums.Length-1];
        
        for(int i=0; i<nums.Length-2; ++i){
            int left = i + 1;
            int right = nums.Length - 1;
            
            while(left < right){
                int currSum = nums[i] + nums[left] + nums[right];
                
                if(currSum == target){
                    return currSum;
                }                                
                
                if(Math.Abs(target - closest) > Math.Abs(target - currSum)){
                    closest = currSum;
                }
                
                if(currSum > target){
                    right--;
                }
                else{
                    left++;
                }
            }
        }
        
        return closest;
    }
}