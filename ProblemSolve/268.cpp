/******************
 * Missing Number *
 ******************/

class Solution {
public:
    int missingNumber(vector<int>& nums) {        
        int len = nums.size();        
        sort(nums.begin(), nums.end());
                
        //정렬 후에 idx에 맞는 숫자가 아니면 리턴
        for(int i=0; i<len; i++){
            if(nums[i] != i){
                return i;
            }
        }
        
        return len;
    }
};