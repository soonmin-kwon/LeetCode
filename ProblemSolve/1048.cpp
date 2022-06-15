/************************
 * Longest String Chain *
 ************************/

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int ans = 1;
        sort(words.begin(), words.end(), [](string& a, string& b){return a.size() < b.size();});
        unordered_map<string, int> dp;
        
        for(auto& word : words){
            if(dp.find(word) == dp.end()){
                dp[word] = 1;
            }
            
            for(int i=0; i<word.size(); ++i){
                string key = word.substr(0, i) + word.substr(i+1);
                
                if(dp.find(key) != dp.end()){
                    dp[word] = dp[key] + 1;
                    ans = max(ans, dp[word]);
                }
            }
        }
        
        return ans;
    }
};