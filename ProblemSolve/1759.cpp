/*****************************************
 * Count Number of Homogenous Substrings *
 *****************************************/

class Solution {
public:
    int countHomogenous(string s) {        
        int len = s.size();
        if(len == 0){
            return 0;
        }
                
        long ans = 0;
        long count = 1;
        
        //연속된 문자열을 세고 1 ~ 연속된 문자열 길이만큼 더해준다
        for(int i=1; i<len; i++){
            if(s[i] == s[i-1]){
                count++;
            }
            else{
                //(n(n+1))/2
                ans = (ans + ((count * (count + 1)) / 2) % 1000000007) % 1000000007;
                count = 1;
            }
        }
        
        ans = (ans + ((count * (count + 1)) / 2) % 1000000007) % 1000000007;
        
        return ans;
    }
};