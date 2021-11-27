/********************************
 * Product of Array Except Self *
 ********************************/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        
        vector<int> prefix(len);
        vector<int> suffix(len);
        vector<int> ans(len);
        
        prefix[0] = nums[0];
        suffix[len-1] = 1;
        
        for(int i=1; i<len; ++i){
            prefix[i] = prefix[i-1] * nums[i];
            suffix[len-i-1] = suffix[len-i] * nums[len-i];
        }
        
        ans[0] = suffix[0];
        
        for(int i=1; i<len; ++i){
            ans[i] = prefix[i-1] * suffix[i];
        }
        
        return ans;
    }
};