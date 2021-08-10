/*********************
 * Find Peak Element *
 *********************/

//참고 : https://leetcode.com/problems/find-peak-element/solution/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        int mid = 0;
        
        //주어진 조건에서 항상 peak가 있을 수 밖에 없다
        //binary search로 탐색 시간을 줄여 peak를 찾는다        
        while(left < right){
            mid = (left + right) / 2;
            
            if(nums[mid] > nums[mid + 1]){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }
        
        return left;
    }
};