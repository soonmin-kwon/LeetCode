/***************************
 * Sort Array By Parity II * 
 ***************************/

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int len = nums.size();        
        int evenIdx = 0;        //nums의 짝수번째 수를 확인하기 위한 idx
        int oddIdx = 1;           //nums의 홀수번째 수를 확인하기 위한 idx
        
        //len -1 번째 수를 확인하기 전까지 계속 진행
        while(evenIdx < len){
            //현재 evenIdx가 범위를 벗어나지 않으면서 짝수이면
            //다음 짝수가 들어올 자리를 확인하면 된다.
            //계속 반복해서 짝수가 들어있을 자리에 홀수가 들어있다면 그 수는 바꿔야만 하는 수이다.
            while(evenIdx < len && !(nums[evenIdx] % 2)){
                evenIdx += 2;
            }
            
            //짝수가 들어있을 자리를 모두 확인, 수정하면 evenIdx == len이 된다.
            if(evenIdx == len){
                break;
            }
            
            //위에 evenIdx와 원리가 같다
            while(oddIdx < len && (nums[oddIdx] % 2)){
                oddIdx += 2;
            }
            
            //oddIdx, evenIdx는 각각 바꿔야만 하는 idx를 나타낸다.
            //고로 두 수를 바꿔주면 요구하는 배열이 완성된다
            swap(nums[oddIdx], nums[evenIdx]);
        }
        
        return nums;
    }
};