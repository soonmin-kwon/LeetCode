/*********************
 * Random Pick Index *
 *********************/

class Solution {
public:    
    unordered_map<int, vector<int>> map;
    
    //각 element별로 index 저장
    Solution(vector<int>& nums) {
        int len = nums.size();
        
        for(int i=0; i<len; i++){
            map[nums[i]].push_back(i);
        }
    }
        
    int pick(int target) {
        int len = map[target].size();
        
        //random한 index 리턴
        return map[target][rand() % len];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */