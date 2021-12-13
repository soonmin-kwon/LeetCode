/**************************
 * Consecutive Characters *
 **************************/

public class Solution {
    public int MaxPower(string s) {
        char prev = '-';
        int ans = 0;
        int count = 1;
        
        foreach(char c in s){
            if(prev == c){
                ++count;
            }
            else{
                ans = Math.Max(ans, count);
                count = 1;
                prev = c;
            }
        }
        
        return Math.Max(ans, count);
    }
}