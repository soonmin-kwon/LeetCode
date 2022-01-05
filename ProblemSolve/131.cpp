/***************************
 * Palindrome Partitioning *
 ***************************/

class Solution {
public:
    //backtracking으로 모든 partition 경우 확인
    void backtracking(vector<vector<string>>& ans, vector<string>& cur, string& s, int start){
        if(start >= s.size()){
            ans.push_back(cur);
            return;
        }
        
        for(int i=start; i<s.size(); i++){
            if(isPalindrome(s, start, i)){
                cur.push_back(s.substr(start, i-start+1));
                backtracking(ans, cur, s, i+1);
                cur.pop_back();
            }
        }
        
        return;
    }
    
    //palindrome인지 확인
    bool isPalindrome(string& s, int start, int end){
        while(start < end){
            if(s[start++] != s[end--]){
                return false;
            }            
        }
        
        return true;
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> cur;
        
        backtracking(ans, cur, s, 0);
        
        return ans;
    }
};