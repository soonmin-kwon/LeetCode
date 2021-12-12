/******************************
 * Partition Equal Subset Sum *
 ******************************/

//참고 : https://leetcode.com/problems/partition-equal-subset-sum/discuss/950659/C%2B%2B-Simple-Dynamic-Programming-Explained-Solution

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num : nums){
            sum += num;
        }
        
        if(sum % 2){
            return false;
        }
        
        sum /= 2;
        
        vector<bool> dp(sum + 1);
        
        dp[0] = true;
        
        for(int num : nums){
            for(int i=sum; i>=num; --i){
                dp[i] = dp[i] || dp[i-num];
            }
        }
        
        return dp[sum];
    }
};