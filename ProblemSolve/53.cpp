/********************
 * Maximum Subarray *
 ********************/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = -10001;
        int tempSubarray = 0;
        
        //Kadane Algorithm
        for(int i=0; i<nums.size(); ++i){
            tempSubarray += nums[i];
            ans = max(ans, tempSubarray);
            tempSubarray = max(tempSubarray, 0);
        }
        
        return ans;
    }
};