/********************
 * Next Permutation *
 ********************/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int permutationStartIdx = 0;
        
        for(int i=0; i<nums.size()-1; ++i){
            if(nums[i] < nums[i+1]){
                permutationStartIdx = max(permutationStartIdx, i);
            }
        }
        
        int swapTargetIdx = 0;
        
        for(int i=permutationStartIdx+1; i<nums.size(); ++i){
            if(nums[permutationStartIdx] < nums[i]){
                swapTargetIdx = max(swapTargetIdx, i);
            }
        }
        
        if(permutationStartIdx == swapTargetIdx){
            reverse(nums.begin(), nums.end());
            return;
        }
        
        swap(nums[permutationStartIdx], nums[swapTargetIdx]);
        reverse(nums.begin() + permutationStartIdx + 1, nums.end());
        
        return;
    }
};