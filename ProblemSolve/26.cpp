/***************************************
 * Remove Duplicates From Sorted Array *
 ***************************************/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {        
        int len = nums.size();
        int idx = 0;
        
        if(len == 0){
            return len;
        }
    
        for(int i=1; i<len; i++){
            //값이 다르면 하나씩 값을 바꾸면서 idx값을 수정
            /* ex) nums = [1,1,2,3]
            *  idx == 0, i == 2 -> nums -> [1, 2, 2, 3]
            *  idx = 1
            *  idx == 1, i == 3 -> nums -> [1, 2, 3, 3]
            *  idx = 2
            */
            
            if(nums[idx] != nums[i]) {
                nums[idx+1] = nums[i];
                idx++;
            }
        }
                
        return idx + 1;
    }
};