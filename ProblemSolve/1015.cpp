/***********************************
 * Smallest Integer Divisible by K *
 ***********************************/

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int remain = 0;
        
        //예외 처리
        if(k % 2 == 0 || k % 5 == 0){
            return -1;
        }
        
        //나머지를 미리 구해도 결과는 같다
        //나머지의 범위가 0~k-1이기 때문에 k번만 돌아도 답을 구할 수 있음
        //나머지가 겹치는 경우는 2, 5로 나눠떨어지는 수 밖에 없음
        for(int ans=1; ans<=k; ans++){
            remain = (remain * 10 + 1) % k;
            
            if(remain == 0){
                return ans;
            }
        }
        
        return -1;
    }
};