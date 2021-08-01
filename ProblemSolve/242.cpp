/*****************
 * Valid Anagram *
 *****************/

class Solution {
public:
    bool isAnagram(string s, string t) {
        int len = s.size();
        
        if(len != t.size()){
            return false;
        }
        //hash map으로 만들어 체크
        unordered_map <char,int> map;        
        
        for(int i=0; i<len; i++){
            //현재 맵에 들어있는지 체크
            auto it = map.find(s[i]);
                        
            //있으면 +1 해주고 없으면 1로 만들어준다.
            if(it != map.end()){
                map[s[i]]++;
            }
            else{
                map[s[i]] = 1;
            }
            
            //위와 똑같이 체크
            auto it2 = map.find(t[i]);
            
            //있으면 -1 해주고 없으면 -1로 만들어준다.
            if(it2 != map.end()){
                map[t[i]]--;
            }
            else{
                map[t[i]] = -1;
            }
        }
        
        //map을 순찰하면서 value가 0이 아니면 리턴
        for(auto it = map.begin(); it!= map.end(); it++){
            if(it->second != 0){
                return false;
            }            
        }
        
        return true;
    }
};