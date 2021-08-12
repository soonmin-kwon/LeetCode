/*************
 * Pow(x, n) *
 *************/

class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        
        //n이 10일 때 비트로 나타내면 1010
        //10 = 8 + 2이고 pow(x,10) = pow(x,8) * pow(x,2)이므로
        //끝자리가 1일때만 곱해주거나 나눠주면 비트 연산처럼 진행할 수 있다
        while(n){
            if(n % 2){
                if(n > 0){
                    ans *= x;
                }
                else{
                    ans /= x;
                }                
            }
            
            x *= x;
            n /= 2;
        }
                
        return ans;
    }
};