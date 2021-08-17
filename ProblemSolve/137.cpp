/********************
 * Single Number II *
 ********************/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unsigned int mask = 1;
        unsigned int ans = 0;
        int count = 0;
        int len = nums.size();
        
        //각 bit의 자리수를 확인하면서 몇개씩 카운트 되는지 확인
        //3개 초과로 나오면 unique한 element의 bit가 된다
        for(int i=0; i<32; i++){
            count = 0;
            
            for(int j=0; j<len; j++){
                if(nums[j] & mask){
                    count += 1;
                }
            }
            
            if((count % 3) != 0){
                ans = ans + mask;
            }
            
            mask <<= 1;
        }
        
        return ans;
    }
};