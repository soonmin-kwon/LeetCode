/************************************
 * Single Element in a Sorted Array *
 ************************************/

public class Solution {
    public int SingleNonDuplicate(int[] nums) {
        int left = 0, right = nums.Length-1, mid = 0;
        
        //똑같은 숫자가 2개씩 들어있기 때문에 정상적으로 들어있다면
        //{0,1}, {2,3}, {4,5} ...의 형식으로 묶여서 같은 값을 가져야 한다
        //binary search를 진행하면서 mid가 홀수인지 짝수인지에 따라 mid-1, mid+1번째 값을 비교해
        //규칙이 틀어진 곳을 찾아 진행하면 된다.
        while(left < right){
            mid = (left + right) / 2;
            
            if((mid % 2 == 1 && nums[mid] == nums[mid-1]) || (mid % 2 == 0 && nums[mid] == nums[mid+1])){
                left = mid + 1;
            }
            else{
                right = mid;
            }
        }
        
        return nums[left];
    }
}