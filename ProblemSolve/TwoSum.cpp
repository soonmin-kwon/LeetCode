class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        vector<int> ans;
                
        for(int i=0; i<nums.size(); i++) {
            int gap = target - nums[i];
            
            auto it = map.find(gap);
            if(it != map.end()) {
                ans.push_back(i);
                ans.push_back(map[gap]);
                
                return ans;                
            }
            else {
                map[nums[i]] = i;
            }
        }
        return ans;
    }
};