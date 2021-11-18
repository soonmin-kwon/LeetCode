/********************************************
 * Find All Numbers Disappeared in an Array *
 ********************************************/

class Solution {
public:
    //1 <= nums[i] <= nums.Length이므로
    //nums[i]-1은 nums 배열의 인덱스로 사용할 수 있다
    //nums에 있는 값을 인덱스로 사용해 그 값을 -로 바꾸면
    //없는 값만 +값으로 남아있고 그 값을 정답에 추가한다
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int idx;
        int len = nums.size();
        vector<int> ans;
        for(int i=0; i<len; ++i){
            idx = (nums[i] < 0 ? -nums[i] : nums[i]) - 1;
            
            if(nums[idx] >= 0){
                nums[idx] = -nums[idx];
            }                        
        }
        
        for(int i=0; i<len; ++i){
            if(nums[i] > 0){
                ans.push_back(i+1);
            }
        }
        
        return ans;
    }
};