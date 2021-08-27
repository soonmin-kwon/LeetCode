/***********************************
 * Longest Uncommon Subsequence II *
 ***********************************/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        //모든 경우의 수를 돌기 때문에
        //현재 s, t가 t,s로 만날 수 있음
        if(s.size() > t.size()){
            return false;
        }
        
        int idx = 0;
        //subsequence인지 확인
        for(int i=0; i<t.size(); i++){            
            if(idx < s.size() && s[idx] == t[i]){
                idx++;
            }
        }

        return idx == s.size();
    }
    
    int findLUSlength(vector<string>& strs) {
        int len = strs.size();
        
        if(len == 0){
            return -1;
        }
        
        int ans = -1;
        
        for(int i=0; i<len; i++) {
            int j =0;
            for(; j<len; j++) {
                if(i == j){
                    continue;
                }
                
                //true면 strs[i+1]을 이용해 탐색
                if(isSubsequence(strs[i], strs[j])){
                    break;
                }                
            }
            
            //i를 기준으로 모든 strs를 탐색했으면 strs[i]는 어떤 strs의 subsequence가 아니다
            //따라서 strs[i]의 길이가 uncommon subsequence의 길이가 된다
            //그 중 최대값을 설정
            if(j == len){
                ans = max(ans, static_cast<int>(strs[i].size()));
            }
            
        }
        
        return ans;
    }
};