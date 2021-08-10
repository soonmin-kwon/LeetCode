/***********************************************************
 * Find First and Last Position of Element in Sorted Array *
 ***********************************************************/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        
        //target이 있는 위치나 들어갈 위치를 찾는다
        int left = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int right = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        
        //lower_bound 값이 맨 뒤에 있으면 배열에 전부 target보다 작은 수만 있는 경우
        if(left == nums.size()){
            return {-1,-1};
        }
        //lower_bound 값이 target과 같지 않으면 값이 없는 경우
        else if(nums[left] != target){
            return {-1, -1};
        }
        
        return {left, right-1};
    }
};