/********************
 * Contiguous Array *
 ********************/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> hash;        
        int ans = 0, remainZeroCount = 0;
        hash[0] = -1;
        
        for(int i=0; i<nums.size(); ++i){
            remainZeroCount += (nums[i] == 1 ? 1 : -1);
            if(hash.find(remainZeroCount) != hash.end()){
                ans = max(ans, i - hash[remainZeroCount]);
            }
            else{
                hash[remainZeroCount] = i;
            }            
        }
        
        return ans;
    }
};