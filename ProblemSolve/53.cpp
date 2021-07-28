/********************
 * Maximum Subarray *
 ********************/

// Kadane 알고리즘
// O(n)의 속도 만족

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        if(len == 1){
            return nums[0];
        }
        
        int sum = 0;
        int ans = -100001;
        
        for(int i=0; i<len; i++){
            ans = max(ans, sum);
            sum = max(sum,0);
        }
        
        return sum;
    }
};