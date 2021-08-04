/********************
 * Shuffle an Array *
 ********************/

class Solution {
public:    
    vector<int> array;
    
    Solution(vector<int>& nums) {
        array = nums;        
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return array;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> after = array;
        int len = array.size();
        
        int random;
        
        //Knuth Shuffle
        for(int i = len -1; i > 0; i--){
            random = rand() % (i + 1);
            swap(after[i], after[random]);
        }
        
        return after;
    }
    
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */