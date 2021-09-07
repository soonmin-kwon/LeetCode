/***********************************
 * Sign of the Product of an Array *
 ***********************************/

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int count = 0;
        
        //음수의 개수만 확인하면 된다
        for(auto x : nums){
            if(x < 0){
                count++;
            }
            
            if(x == 0){
                return 0;
            }
        }
        
        return ((count % 2) ? -1 : 1);
    }
};