/*****************
 * Single Number *
 *****************/

class Solution {
public:    
    // Solution 4
    int singleNumber(vector<int>& nums) {
        int start = nums[0];        
        int len = nums.size();
        
        // 같은 수를 XOR하면 0
        // 한번 연산 된 수만 남음
        for(int i = 1; i<len; i++){
            start ^= nums[i];
        }
        
        return start;
    }
   
    int singleNumber(vector<int>& nums) {
        //정렬 후 연속되는 값이 나오지 않으면 답
        sort(nums.begin(), nums.end());
        int start = nums[0];
        int count = 1;
        int len = nums.size();
        
        for(int i=1; i<len; i++){
            //이전 값과 같으면 count를 올려주고
            if(nums[i] == start){
                start = nums[i];
                count++;
            }
            //다를 때 count가 1이면 답
            //count가 1이 아니면 기준 값 초기화
            else{
                if(count == 1){
                    return start;
                }
                
                count = 1;
                start = nums[i];
            }
        }   
        
        return start;
    }
};