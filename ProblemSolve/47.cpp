/*******************
 * Permutations II *
 *******************/

class Solution {
public:
    void backtracking(vector<vector<int>>& ans, vector<int> num, int start, int end){
        if(start == end - 1){
            ans.push_back(num);
            return;
        }
        
        for(int i=start; i<end; ++i){
            if(i != start && num[i] == num[start]){
                continue;
            }
            
            swap(num[i], num[start]);
            backtracking(ans, num, start + 1, end);
        }
    }
    
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        
        backtracking(ans, nums, 0, nums.size());
        
        return ans;
    }
};