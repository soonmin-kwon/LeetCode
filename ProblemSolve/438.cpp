/*********************************
 * Find All Anagrams in a String *
 *********************************/

//참고 : 567번 문제와 같은 문제

class Solution {
public:    
    vector<int> findAnagrams(string s, string p) {
        vector<int> countChar(26);
        vector<int> window(26);
        vector<int> ans;
        
        //주어진 문자열 p에 있는 모든 char의 개수를 센다
        for(auto ch : p){
            countChar[ch - 'a']++;
        }
        
        //p의 anagram이 있는지 확인, p로 만들 수 있는 모든 문자열 중에 하나가 들어있는지 확인
        //p의 길이만큼의 window를 만들어 그 window에 들어있는 모든 문자가 p에 들어있는 모든 문자와 같은지 확인
        for(int i=0; i<s.size(); i++){
            //s에 있는 char의 개수를 세서 p의 anagram이 있는지 확인
            //countChar와 window가 같다면 s에 p의 anagram이 있다는 뜻
            window[s[i] - 'a']++;
            
            //윈도우의 범위가 더 이상 늘어나지 않도록 값을 빼준다
            if(i >= p.size()){
                window[s[i - p.size()] -'a']--;
            }
            
            //countChar와 window가 같은지 확인
            //같으면 window가 시작한 지점의 idx 값을 답에 추가
            //p = "ab", s = "abab"라면, countChar[0] = countChar[1] = 1이기 때문에 window[0] = window[1] = 1이어야만 anagram이 있다고 할 수 있다
            //window[0] = window[1] = 1을 만족하는 경우는 "ab", "ba", "ab"이고 각 정답의 시작 idx는 0, 1, 2이다
            if(countChar == window){
                ans.push_back(i - p.size() + 1);
            }
        }
        
        return ans;
    }
};
