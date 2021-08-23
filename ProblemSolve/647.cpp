/**************************
 * Palindromic Substrings *
 **************************/

class Solution {
public:
    int countSubstrings(string s) {
        int mid, left;
        int right = 0;
        int ans = 0;
        int len = s.size();
        
        //모든 index에서 palindromic한지 체크
        for(int i=0; i<len; i++){
            mid = i;
            left = mid - 1;
            right = mid + 1;
            //길이가 1인 substring은 무조건 palindromic
            ans++;
            
            //홀수 길이 substring
            while(left >= 0 && right < len){
                //palindromic한지 체크하면서 정답 증가
                if(s[left] == s[right]){
                    ans++;
                    left--;
                    right++;
                }
                else{
                    break;
                }
            }
            
            //짝수 길이 substring
            if(i < len - 1 && s[i] == s[i+1]){
                left = mid - 1;
                right = mid + 2;
                //if문에서 s[i] == s[i+1]로 체크했기 때문에 하나 추가
                ans++;
                
                while(left >= 0 && right < len){
                    if(s[left] == s[right]){
                        ans++;
                        left--;
                        right++;
                    }
                    else{
                        break;
                    }
                }
            }
        }
        
        return ans;
    }
};