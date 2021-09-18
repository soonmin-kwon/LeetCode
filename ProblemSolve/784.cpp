/***************************
 * Letter Case Permutation *
 ***************************/

class Solution {
public:
    //주어진 문자열을 처음부터 탐색하면서 조건에 맞게 케이스를 추가한다
    void permutation(vector<string>& ans, string s, string cur, int idx, int size){
        //주어진 문자열만큼 만들었으면 정답에 추가
        if(cur.size() == size){
            ans.push_back(cur);
            return;
        }
        
        //알파벳이 아닌 경우는 그대로 진행
        if(isdigit(s[idx])){
            cur += s[idx];
            permutation(ans, s, cur, idx + 1, size);
        }
        //알파벳인 경우에는 소문자와, 대문자 케이스로 나눠서 진행
        else{
            char temp = s[idx];      
            //소문자로 진행
            permutation(ans, s, cur + (char)tolower(temp), idx + 1, size);
        
            //대문자로 진행
            permutation(ans, s, cur + (char)toupper(temp), idx + 1,  size);
        }
        
        return;
    }
    
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        
        permutation(ans, s, "", 0, s.size());
        
        return ans;
    }
};