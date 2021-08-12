/***********************
 * Sum of Two Integers *
 ***********************/

class Solution {
public:
    int getSum(int a, int b) {
        //b(carry)가 0이 되면 리턴
        if(b == 0){
            return a;
        }
        
        //xor연산을 통해 서로 다를 경우만 더해놓는다
        int x = a ^ b;
        //and연산을 통해 carry를 계산
        //음수 처리
        int carry = (unsigned int)(a & b)<<1;        
        
        //carry와 xor연산한 결과를 다시 더함
        //carry가 발생하지 않을 때까지
        return getSum(x, carry);        
    }
};