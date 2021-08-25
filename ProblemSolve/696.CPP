/***************************
 * Count Binary Substrings *
 ***************************/

//참고 : https://leetcode.com/problems/count-binary-substrings/solution/

class Solution {
public:
    int countBinarySubstrings(string s) {
        int len = s.size();
        //연속된 0이나 1의 개수 저장        
        int count = 1;  //현재 탐색하고있는 연속된 0이나 1의 개수
        int prev = 0;   //이전에 탐색했던 연속된 0이나 1의 개수
        int ans = 0;        
        
        for(int i=1; i<len; i++){
            if(s[i-1] != s[i]){
                //만약 prev가 2, count가 3이면 이 스트링은 00111xxxx,이거나 11000xxxx이다
                //00111로 만들 수 있는 문자열은 01, 0011이고 11000으로 만들 수 있는 문자열은 10, 1100이므로
                //min(prev, count)만큼 문자열을 만들 수 있다.                
                ans += min(prev, count);
                prev = count;
                count = 1;
            }
            else{
                count++;
            }
        }
        
        //나머지 값 추가
        return ans + min(prev, count);
    }
};