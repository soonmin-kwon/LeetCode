/********************
 * Find Pivot Index *
 ********************/

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int len = nums.size();
        int sumL = 0;
        int sumR = 0;
        vector<int> prefix(len);
        
        prefix[0] = nums[0];
        for(int i=1; i<len; i++){
            prefix[i] = prefix[i-1] + nums[i];
        }
        
        
        for(int i=0; i<len; i++){
            //prefix[i] = nums[0] ~ nums[i]까지의 합
            
            //sumL은 nums[0] ~ nums[i-1]까지의 합
            sumL =  prefix[i] - nums[i];
            //sumR은 nums[i+1] ~ nums[len -1]까지의 합
            sumR =  prefix[len -1] - prefix[i];
            
            if(sumL == sumR){
                return i;
            }
        }

        return -1;
    }
};