/*****************************
 * Reverse Words in a String *
 *****************************/

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);        
        string temp = "", ans = "";
        
        //단어로 분리하면서 이전에 나온 단어를 뒤에 붙인다
        //ex) the sky is blue
        //temp = "the", ans = "the "
        //temp = "sky", ans = "sky the "
        //temp = "is", ans = "is sky the "
        //temp = "blue", ans = "blue is sky the "
        while(ss >> temp){
            ans = temp + " " + ans;
        }
        
        //맨 뒤에 공백이 하나 들어가있기 때문에 공백 제거
        ans.pop_back();
        
        return ans;
    }
};