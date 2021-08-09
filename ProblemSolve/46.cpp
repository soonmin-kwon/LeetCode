/****************
 * Permutations *
 ****************/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;        
        sort(nums.begin(), nums.end());
        
        //next_permutation을 이용해 모든 경우 추가
        do{
            ans.push_back(nums);
        }while(next_permutation(nums.begin(), nums.end()));
        
        return ans;
    }
};