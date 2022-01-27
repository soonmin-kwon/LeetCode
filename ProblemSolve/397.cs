/***********************
 * Integer Replacement *
 ***********************/

public class Solution {
    int ans = 0;
    
    public int IntegerReplacement(int n) {
        if(n == 1){
            return ans;
        }
        
        if(n == Int32.MaxValue){
            return 32;
        }
        
        if(n == 3){
            ans += 2;
            return ans;
        }
        
        if(n % 2 == 1){
            ans++;
            if((n+1) % 4 == 0){
                IntegerReplacement(n+1);
            }
            else{
                IntegerReplacement(n-1);
            }
        }
        else{
            ans++;
            IntegerReplacement(n/2);
        }
                
        return ans;
    }
}