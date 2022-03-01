/*****************
 * Counting Bits *
 *****************/

public class Solution {
    public int[] CountBits(int n) {
        int[] ans = new int[n+1];
        ans[0] = 0;
        
        if(n == 0){
            return ans;
        }
        
        ans[1] = 1;
        int divisor = 2;
        
        for(int i=2; i<=n; ++i){
            if(i % divisor == 0){
                divisor = i;
            }
            
            ans[i] = ans[i - divisor] + 1;
        }
        
        return ans;
    }
}