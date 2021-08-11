/**********************************
 * Search in Rotated Sorted Array *
 **********************************/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() -1;
        int mid = 0;
        
        //binary search
        while(left <= right){
            //입력 범위가 overflow 발생 x
            mid = (right + left) / 2;
            
            //target을 찾으면 return
            if(nums[mid] == target){
                return mid;
            }
            //어떤 idx를 기준으로 왼쪽 오른쪽 각각 오름차순으로 정렬되어 있는 상황
            //왼쪽 구간에 속해있는지 확인
            else if(nums[mid] >= nums[left]){
                //속해 있으면 right 값을 좁힘
                if(nums[left] <= target && nums[mid] >= target){
                    right = mid - 1;
                }
                //속해 있지 않으면 left값을 좁힘
                else{
                    left = mid + 1;
                }
            }            
            //오른쪽 구간에 속해있는지 확인
            else{
                if(nums[mid] <= target && nums[right] >= target){
                    left = mid + 1;
                }
                else{
                    right = mid -1;
                }
            }
        }
        
        return -1;
    }
};