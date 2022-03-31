/********************************
 * Sum of All Subset XOR Totals *
 ********************************/

class Solution {
public:
    void backtracking(vector<int>& nums, int idx, int curXor, int& ans){
        if(idx >= nums.size()){
            return;
        }
        
        for(int i=idx; i<nums.size(); ++i){
            ans += (curXor ^ nums[i]);
            backtracking(nums, i + 1, curXor ^ nums[i], ans);
        }
    }
    
    int subsetXORSum(vector<int>& nums) {
        int ans = 0;
        backtracking(nums, 0, 0, ans);
        
        return ans;
    }
};