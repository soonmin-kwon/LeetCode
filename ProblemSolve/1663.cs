/**********************************************
 * Smallest String With A Given Numeric Value *
 **********************************************/

public class Solution {
    public string GetSmallestString(int n, int k) {
        StringBuilder builder = new StringBuilder();
        
        int idx = n-1;
        k -= n;
        
        for(int i=0; i<n; ++i){
            builder.Append('a');
        }
        
        while(k > 0 && idx >= 0){
            if(k >= 25){
                builder[idx] = (char)(builder[idx] + 25);
                k -= 25;
            }
            else{
                builder[idx] = (char)(builder[idx] + k);
                k = 0;
            }
            
            idx--;
        }
        
        return builder.ToString();
    }
}