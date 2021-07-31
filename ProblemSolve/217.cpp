/**********************
 * Contains Duplicate *
 **********************/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        //정렬해서 다음 값과 이전 값을 비교
        sort(nums.begin(), nums.end());        
        int len = nums.size();        
        int start = nums[0];
                
        for(int i=1; i<len; i++){
            //다음 값이랑 같으면 true
            if(start == nums[i]){
                return true;
            }
            //다르면 기준 값을 바꿈
            else {
                start = nums[i];
            }
        }
        
        return false;
    }
};