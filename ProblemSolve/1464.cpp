/***********************************************
 * Maximum Product of Two Elements in an Array *
 ***********************************************/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //가장 큰 두 수가 앞으로 오게 정렬한다
        nth_element(nums.begin(), nums.begin() + 1, nums.end(), greater<int>());
        
        //product
        return (nums[0] - 1) * (nums[1] - 1);
    }
};