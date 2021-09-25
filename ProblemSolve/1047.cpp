/***********************************
 * Remove All Duplicates in String *
 ***********************************/

class Solution {
public:
    string removeDuplicates(string s) {
        string ans = "";
        
        //주어진 문쟈열을 돌면서 연속된 두 개의 char이 같은 경우 제거
        for(auto ch : s){
            
            //ans를 하나의 스택으로 생각하면 스택의 top은 ans.back()이다
            //ex) s = "abbaca"
            //    ans = "a"
            //    ans = "ab"
            //    ans = "a"
            //    ans = ""
            //    ans = "c"
            //    ans = "ca"
            if(!ans.empty() && ch == ans.back()){
                ans.pop_back();
            }
            else{
                ans.push_back(ch);
            }
        }
        
        return ans;
    }
};