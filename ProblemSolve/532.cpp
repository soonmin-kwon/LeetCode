/****************************
 * K-diff Pairs in an Array *
 ****************************/

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        unordered_set<int> ansSet;
        
        for(int i=0; i<nums.size(); ++i){
            if(hash.count(nums[i] - k)){
                ansSet.insert(nums[i]);
            }
            
            if(hash.count(nums[i] + k)){
                ansSet.insert(nums[i] + k);
            }

            hash[nums[i]]++; 
        }
        
        return ansSet.size();
    }
};