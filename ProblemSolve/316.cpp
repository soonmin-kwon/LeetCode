/****************************
 * Remove Duplicate Letters *
 ****************************/

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> candidate(256);
        vector<bool> visitied(256);
        
        for(char ch : s){
            candidate[(int)ch]++;
        }
        
        string ans = "0";
        for(char ch : s){
            candidate[(int)ch]--;
            
            if(visitied[ch]){
                continue;
            }
            
            while(ch < ans.back() && candidate[ans.back()] != 0){
                visitied[ans.back()] = false;
                ans.pop_back();
            }
            
            ans += ch;
            visitied[ch] = true;
        }
        
        return ans.substr(1);
    }
};