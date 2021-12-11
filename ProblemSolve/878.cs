/**********************
 * Nth Magical Number *
 **********************/

//참고 : https://leetcode.com/problems/nth-magical-number/solution/

public class Solution {
    public int GCD(int x, int y){
        if(x == 0){
            return y;
        }
        
        return GCD(y % x, x);
    }
    
    public int NthMagicalNumber(int n, int a, int b) {
        int mod = 1000000007;
        int lcm = a / GCD(a, b) * b;
        
        long low = 0, high = (long)n * Math.Min(a,b);
        
        while(low < high){
            long mid = low + (high - low)/2;
            
            if(mid / a + mid / b - mid / lcm < n){
                low = mid + 1;
            }
            else{
                high = mid;
            }
        }
        
        return (int)(low % mod);
    }
}