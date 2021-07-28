/***********************
 * Length of Last Word *
 ***********************/


class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.length();
        int ans = 0;
        
        // 모든 문자열이 단어로 끝나지 않기 때문에 오른쪽 끝에서부터 체크
        // 오른쪽 끝부터 확인하면서 연속된 문자열들을 세고
        // 공백이 나왔을 때 ans가 초기 값이 아니면 ans를 return한다.
        // ex) "a   b  " 같은 문자열도 해결할 수 있다.
        
        for(int i= len-1; i>=0; i--){
            if(s[i] != ' '){
                ans++;
            }
            else{
                if(ans !=0){
                    return ans;
                }
            }
        }
        
        return ans;
    }
};