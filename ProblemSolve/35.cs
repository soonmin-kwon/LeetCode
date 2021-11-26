/**************************
 * Search Insert Position *
 **************************/

public class Solution {
    public int SearchInsert(int[] nums, int target) {
        int left = 0, right = nums.Length-1;
        int mid = 0;
        
        //Binary Search
        while(left < right){
            mid = (left + right)/2;
            
            if(nums[mid] > target){
                right = mid-1;
            }
            else if(nums[mid] < target){
                left = mid+1;
            }
            else{
                return mid;
            }
        }
        
        //nums에 target이 없으면 while문을 통과한다        
        if(nums[left] < target){
            return left+1;
        }
        
        return left;
    }
}