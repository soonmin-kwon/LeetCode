/*******************
 * Remove K Digits *
 *******************/

public class Solution {
    public string RemoveKdigits(string num, int k) {
        string ans = "";
        
        foreach(char digit in num){
            while(ans.Length != 0 && (int)ans[ans.Length-1] > (int)digit && k > 0){
                ans = ans.Remove(ans.Length - 1);
                k--;
            }
            
            if(ans.Length != 0 || digit != '0'){
                ans = ans + digit;
            }
        }
        
        while(ans.Length != 0 && k > 0){
            k--;
            ans = ans.Remove(ans.Length - 1);
        }
        
        return ans =="" ? "0" : ans;
    }
}