/******************
 * Summary Ranges *
 ******************/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size() == 0){
            return {};
        }
        
        int start = nums[0];
        int prev = nums[0];
        vector<string> ans;
        
        for(int i=1; i<nums.size(); ++i){
            if(nums[i] - 1 != prev){
                if(start == prev){
                    ans.push_back(to_string(start));
                }
                else{
                    ans.push_back(to_string(start) + "->" + to_string(prev));
                }                
                start = nums[i];
            }
            
            prev = nums[i];
        }
        
        if(start == prev){
            ans.push_back(to_string(start));
        }
        else{
            ans.push_back(to_string(start) + "->" + to_string(prev));
        }                
        
        return ans;
    }
};