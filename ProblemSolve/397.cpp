/***********************
 * Integer Replacement *
 ***********************/

class Solution {
public:
    int ans = 0;
    
    int integerReplacement(int n) {
        if(n == 1){
            return ans;
        }
        
        if(n == 3){
            ans += 2;
            return ans;
        }
        
        if(n == INT_MAX){
            return 32;
        }
        
        if(n % 2){
            ans++;
            
            if((n+1) % 4 == 0){
                integerReplacement(n+1);
            }
            else{
                integerReplacement(n-1);
            }
        }
        else{
            ans++;
            integerReplacement(n/2);
        }
        
        return ans;
    }
};