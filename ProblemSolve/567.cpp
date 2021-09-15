/*************************
 * Permutation in String *
 *************************/

//참고 : https://leetcode.com/problems/permutation-in-string/discuss/357821/C%2B%2B-Concise-Solution

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> countChar(26);
        vector<int> window(26);
        
        //주어진 문자열 s1의 char의 개수를 센다
        for(auto ch : s1){
            countChar[ch - 'a']++;
        }
        
        //s1의 permutation이 있는지 확인한다, s1의 permutation이 연속되게 있어야 하므로 window를 만들어 체크한다
        for(int i=0; i<s2.size(); i++){
            //s2에있는 char의 개수를 센다
            window[s2[i] - 'a']++;
            
            //s1의 길이를 갖는 window를 만들어 점검한다
            //현재 i값이 s1의 길이를 넘어가면 window를 한 칸씩 움직인다
            //ex) s1 = "ab", s2 = "eibaoo"
            //countChar[0] = 1, countChar[1] = 1
            //i = 0, window[4] = 1
            //i = 1, window[4] = 1, window[8] = 1;
            //i = 2, window[4] = 1, window[8] = 1, window[1] = 1, i >= si.size() -> window[4] = 0
            //window != countChar
            //i = 3, window[8] = 1, window[1] = 1, window[0] = 1, i >= si.size() -> window[8] = 0
            //window == countChar -> return true            
            if(i >= s1.size()){
                window[s2[i - s1.size()] - 'a']--;
            }
            
            if(countChar == window){
                return true;
            }
        }
       
        return false;
    }
};