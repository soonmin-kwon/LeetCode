/*****************
 * Counting Bits *
 *****************/

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);
        
        if(n == 0){
            return ans;
        }
        
        ans[1] = 1;
        int divisor = 2;
        for(int i=2; i<=n; ++i){
            if(i % divisor == 0){
                divisor = i;
            }
            
            ans[i] = ans[i-divisor] + 1;
        }
        
        return ans;
    }
};