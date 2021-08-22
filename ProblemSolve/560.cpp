/**************************
 * Subarray Sums Eqauls K *
 **************************/

//참고 : https://leetcode.com/problems/subarray-sum-equals-k/solution/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int len = nums.size();
        int sum = 0;
        int ans = 0;
        unordered_map<int, int> map;
        map[0] = 1;
        
        for(int i=0; i<len; i++){
            sum += nums[i];
                        
            if(map.find(sum - k) != map.end()){
                ans += map[sum - k];
            }
            
            map[sum]++;
        }
        
        return ans;
    }
};