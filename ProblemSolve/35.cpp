/**************************
 * Search Insert Position *
 **************************/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // nums가 sorted 되어 있고고, O(log n)의 시간 복잡도를 가져야 하기 때문에
        // lower_bound를 사용
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};