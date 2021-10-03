/*******************
 * Monotonic Array *
 *******************/

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool isIncreasing = true;       //monotone increasing인지 확인
        bool isDecreasing = true;       //monotone decreasing인지 확인
        
        for(int i=1; i<nums.size(); i++){
            //decreasing인 경우 isIncreasing이 false로 변경
            if(nums[i-1] > nums[i]){
                isIncreasing = false;
            }
            
            //increasing인 경우 isDecreasing이 false로 변경
            if(nums[i-1] < nums[i]){
                isDecreasing = false;
            }
        }
        
        //isIncreasing, isDecreasing이 모두 false인 경우에만 false를 리턴
        //위의 경우는 한 배열안에 증가하는 부분과 감소하는 부분이 같이 존재한다는 뜻
        //고로 monotonic array가 아닌 경우이다
        return isIncreasing || isDecreasing;
    }
};