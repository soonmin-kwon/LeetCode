/**********************************
 * Increasing Triplet Subsequence *
 **********************************/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX;
        int second = INT_MAX;
        int len = nums.size();
        
        //0부터 끝까지 순환하기 때문에 가능
        for(int i=0; i<len; i++){            
            if(nums[i] <= first){
                first = nums[i];
            }
            else if(nums[i] <= second){
                second = nums[i];
            }
            else{
                return true;
            }
        }
        
        return false;
    }
};