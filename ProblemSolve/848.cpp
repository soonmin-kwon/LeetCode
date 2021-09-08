/********************
 * Shifting Letters *
 ********************/

class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int len = shifts.size();
        
        s[len - 1] = (s[len - 1] - 'a' + shifts.back()) % 26 + 'a';
        
        for(int i=len - 2; i>=0; i--){
            //shifts[i]가 26이면 다시 원상태, 26으로 나눈 나머지만큼만 shift하면 된다.
            //shift값을 갱신하면서 같이 s값도 갱신한다.
            shifts[i] = (shifts[i] + shifts[i + 1]) % 26;
            s[i] = ((s[i] - 'a' + shifts[i]) % 26) + 'a';            
        }          

        return s;
    }
};