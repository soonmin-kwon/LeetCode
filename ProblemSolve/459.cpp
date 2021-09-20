/******************************
 * Repeated Substring Pattern *
 ******************************/

//참고 : https://leetcode.com/problems/repeated-substring-pattern/discuss/441605/kmp-or-O(n)

class Solution {
public:
    //주어진 문자열 중에서 prefix == suffix가 될 수 있는 substring 중에서
    //가장 긴 것의 길이를 pi에 저장한다
    //KMP Algorithm
    bool repeatedSubstringPattern(string s) {
        int len = s.size();
        int j = 0;
        
        vector<int> pi(len, 0);
        
        for(int i=1; i<len; i++){
            while(j > 0 && s[i] != s[j]){
                j = pi[j-1];
            }
            
            if(s[i] == s[j]){
                pi[i] = ++j;
            }
        }
                
        //만약 s = "ababab"라면, pi = [0, 0, 1, 2, 3, 4]이다
        //repeating string의 길이는 2이고 전체 문자열 중에 repeating string의 char이 겹치는 횟수는 4가 된다
        //len - pi[len - 1]은 repeating string의 길이를 나타내고
        //pi[len - 1]이 repeating string의 길이로 나눠 떨어지면 repeating string으로 이뤄진 pattern을 가지고 있게된다
        return pi[len-1] && !(pi[len - 1] % (len - pi[len - 1]));
    }
};