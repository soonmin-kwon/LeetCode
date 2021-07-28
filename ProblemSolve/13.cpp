/********************
 * Roman to Integer *
 ********************/

class Solution {
public:
    int romanToInt(string s) {
        //unordered_map을 만들어 char 값에 따른 int값을 빠르게 찾도록 한다.
        unordered_map<char, int> uM;        
        
        uM['I'] = 1;
        uM['V'] = 5;
        uM['X'] = 10;
        uM['L'] = 50;
        uM['C'] = 100;
        uM['D'] = 500;
        uM['M'] = 1000;
                        
        int ans = uM[s.back()];
        int len = s.size();
        
        //뒤에서 부터 접근
        for(int i=len-2; i>=0; i--) {
            // 뒤가 앞보다 클 때 ex) IV
            if(uM[s[i]] < uM[s[i + 1]]) {
                ans -= uM[s[i]];
            }
            else {
                ans += uM[s[i]];
            }
        }
        
        return ans;
    }
};