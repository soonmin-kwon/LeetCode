/**************************************
 * First Unique character in a String *
 **************************************/

class Solution {
public:    
    int firstUniqChar(string s) {
        int checkChar[26] = {0, };
        int len = s.size();
        
        if(len == 1){
            return 0;
        }
        
        //전체 스트링을 돌면서 카운트
        for(int i=0; i<len; i++){            
            checkChar[s[i] - 'a']++;
        }
        
        //한번만 카운트 됐으면 바로 리턴
        for(int i=0; i<len; i++){
            if(checkChar[s[i] - 'a'] == 1){
                return i;
            }
        }
             
        //한번 카운트 된 캐릭터가 없으면 -1
        return -1;
    }
    
    //쓸데없이 어렵게 푼 코드
    int firstUniqChar(string s) {
        unordered_map<char, int> map;
        int len = s.size();
        
        for(int i =0; i<len; i++){
            auto it = map.find(s[i]);
            
            if(it != map.end()){
                s[map[s[i]]] = '*';
                s[i] = '*';
            }
            else{
                map[s[i]] = i;
            }
        }
        int ans = find_if(s.begin(), s.end(), 
                    [](const char c){
                        return c != '*';
                    }) - s.begin();
        
        if(ans == len){
            return -1;
        }
        
        return ans;
    }
};