/**************************************************
 * Minimum Value to Get Positive Step by Step Sum *
 **************************************************/

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int minSumOfNums = 0, sumOfNums = 0;
        
        //nums의 sum중에 가장 작은 값보다 1큰 값으로 시작하면
        //시작 값과 nums의 모든 element를 차례대로 더해도 0이 되지 않는다
        for(int num : nums){
            sumOfNums += num;            
            minSumOfNums = min(minSumOfNums, sumOfNums);
        }
        
        return 1 - minSumOfNums;
    }
};