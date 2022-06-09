/**************************************
 * Two Sum II - Input Array Is Sorted *
 **************************************/

public class Solution {
    public int[] TwoSum(int[] numbers, int target) {
        int left = 0;
        int right = numbers.Length - 1;
        List<int> ans = new List<int>();
        
        while(left <= right){
            if(numbers[left] + numbers[right] < target){
                left++;
            }
            else if(numbers[left] + numbers[right] > target){
                right--;
            }
            else{
                ans.Add(left + 1);
                ans.Add(right + 1);
                break;
            }
        }
        
        return ans.ToArray();
    }
}