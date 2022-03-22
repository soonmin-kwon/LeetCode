/**********************************************
 * Smallest String With A Given Numeric Value *
 **********************************************/

class Solution {
public:
    string getSmallestString(int n, int k) {
        int idx = n-1;
        k -= n;
        
        string ans = "";
        for(int i=0; i<n; ++i){
            ans += 'a';
        }
        
        while(k > 0 && idx >= 0){
            if(k >= 25){
                ans[idx] = ans[idx] + 25;
                k -= 25;
            }
            else{
                ans[idx] = ans[idx] + k;
                k = 0;
            }
            
            idx--;
        }
        
        return ans;
    }
};