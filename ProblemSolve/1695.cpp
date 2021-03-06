/*************************
 * Maximum Erasure Value *
 *************************/

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int curSum = 0;
        int left = 0;
        int right = 0;
        int ans = 0;
        vector<int> hash(10001, 0);
        
        while(right < nums.size()){
            hash[nums[right]]++;
            curSum += nums[right];
            
            while(hash[nums[right]] > 1){
                hash[nums[left]]--;
                curSum -= nums[left];
                left++;
            }
            
            ans = max(ans, curSum);
            right++;
        }
        
        return ans;
    }
};