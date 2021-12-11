/**********************
 * Nth Magical Number *
 **********************/

//참고 : https://leetcode.com/problems/nth-magical-number/solution/

class Solution {
public:
    int gcd(int x, int y) {
        if (x == 0){
            return y;
        }
        
        return gcd(y % x, x);
    }
    
    //O(n)은 시간 초과
    int nthMagicalNumber(int n, int a, int b) {
        int mod = 1000000007;
        int lcm = a / gcd(a, b) * b;

        long low = 0;
        long high = (long) n * min(a, b);
        while (low < high) {
            long mid = low + (high - low) / 2;

            if (mid / a + mid / b - mid / lcm < n)
                low = mid + 1;
            else
                high = mid;
        }

        return (int)(low % mod);
    }    
};