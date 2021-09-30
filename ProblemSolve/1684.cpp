/******************************************
 * Count the Number of Consistent Strings *
 ******************************************/

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {    
        bool hash[26] = {};     //allowed에 있는 char이면 true
        int ans = words.size();
        
        //allowed 에 들어있는 문자열을 체크
        for(auto ch : allowed){
            hash[ch - 'a'] = true;
        }
        
        //각 word가 allowed의 char로만 이뤄져 있는 단어인지 체크
        //모든 단어를 전부 검사한다
        for(auto word : words){
            //각 char를 확인하면서 allowed에 들어있는지 hash 배열을 통해 확인
            for(auto ch : word){                
                if(!hash[ch-'a']){
                    ans--;
                    break;
                }
            }
        }
        
        return ans;
    }
};