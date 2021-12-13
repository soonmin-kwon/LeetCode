/**************************
 * Consecutive Characters *
 **************************/

class Solution {
public:
    int maxPower(string s) {
        int ans = 0;
        int count = 1;
        char prev = '-';
        for(char ch : s){
            if(prev == ch){
                count++;
            }
            else{
                ans = max(ans, count);
                prev = ch;
                count = 1;
            }
        }
        
        return max(ans,count);
    }
};