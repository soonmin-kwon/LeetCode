/***************************
 * Sum of Digits in Base K *
 ***************************/

class Solution {
public:
    int sumBase(int n, int k) {
        int idx = 1;
        int remain;
        int carry;
        int convert = 0;
        
        //n을 k진수로 변환
        while(n){
            carry = n / k;
            remain = n % k;
            
            n = carry;
            convert += (idx * remain);
            
            idx *= 10;
        }
        
        //k진수로 변환한 수가 10보다 작을 시 그냥 정답
        if(convert < 10){
            return convert;
        }
        
        int ans = 0;
        
        //k진수로 변환한 수의 각 자리수를 더해준다
        while(convert){
            ans += convert % 10;
            convert /= 10;
        }
        
        return ans;
    }
};