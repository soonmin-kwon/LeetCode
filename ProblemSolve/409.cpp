/**********************
 * Longest Palindrome *
 **********************/

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> frequency;      //s에 있는 char들의 frequency를 저장
        int ans = 0;
        bool isOdd = true;                      //홀수개인지 체크
        
        //frequency 측정
        for(char ch : s){
            frequency[ch]++;
        }
        
        for(auto it = frequency.begin(); it != frequency.end(); it++){
            //frequency가 2이상이면 palindrome에 추가할 수 있다.            
            if(it -> second / 2){
                //frequency가 2n이면 길이가 2n만큼 늘어나고
                //frequency가 2n + 1이어도 길이가 2n만큼 늘어나야 한다                
                ans += 2 * (it -> second / 2);
                
                //사용하고 남은 char의 개수를 다시 저장한다
                it -> second %= 2;
            }
            
            //사용하고 남은 char이 홀수개이면 하나 추가할 수 있다.
            //한번 홀수개의 char을 사용하면 다른 홀수개의 char은 절대 사용할 수 없다
            if(it -> second && isOdd){
                ans += 1;
                isOdd = false;
            }
        }
        
        return ans;
    }
};