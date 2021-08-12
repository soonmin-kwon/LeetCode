/****************************
 * Fatorial Trailing Zeroes *
 ****************************/

class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        
        // n! 이기때문에 5의 개수만 세줘도 10의 자리수를 찾을 수 있다
        // 25, 125, 625 ... 5의 거듭제곱일 때 하나씩 0이 더 늘어난다
        for(int i = 5; i<=n; i*= 5){
            ans += n / i;
        }
        
        return ans;
    }
};