/*********************
 * Single Number III *
 *********************/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {        
        unsigned long long x = 0;
        int len = nums.size();
        
        if(len == 2){
            return nums;
        }
        
        //중복되는 수는 사라지고 최종적으로 unique한 두 element값의 xor이 남는다
        for(int i=0; i<len; i++){
            x ^= nums[i];
        }
        
        int idx = 0;
        
        //x = a^b라고 가정했을 때
        //x의 bit를 확인하면 두 수는 다른 수 이기때문에 반드시 1이 있는 곳이 존재한다        
        //그 1이 있는 지점에서 모든 수를 확인하면 두 그룹으로 나눠질 수 있다
        //ex) [1,2,1,3,2,5] -> 3 ^ 5 = 110, idx = 1
        //2^1번째 bit가 0인 그룹 {1, 1, 5}, 1인 그룹 {2, 2, 3}        
        for(int i=0; i<32; i++){
            if( (x >> i) & 1){
                idx = i;
                break;
            }
        }
        
        int xFirst = 0;
        int xSecond = 0;
        
        
        //각 그룹에 있는 모든 원소를 xor 하면 서로 다른 a와 b만 남게된다
        for(int i=0; i<len; i++){
            if((nums[i] >> idx) & 1){
                xFirst ^= nums[i];
            }
            else{
                xSecond ^= nums[i];
            }
        }
        
        return {xFirst, xSecond};
    }
};