/***********************************************************
 * Maximum Number of Vowels in a Substring of Given Length *
 ***********************************************************/

class Solution {
public:
    //vowel인지 아닌지 확인
    bool check(char a){
        if(a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u'){
            return true;
        }
        
        return false;
    }
    
    int maxVowels(string s, int k) {
        int len = s.size();
        int temp = 0;
        int ans = 0; 
                        
        //처음부터 window 범위만큼 체크
        for(int i=0; i<k; i++){
            if(check(s[i])){
                ans++;
            }
        }
    
        temp = ans;
        
        //window를 한칸 옆으로 옮기면서 확인
        for(int i=1, j = k; j<len; j++, i++){
            //이전에 있던 칸이 vowel에 속해있으면 - 1            
            if(check(s[i-1])){
                temp--;
            }

            //새로 범위내에 들어온 칸이 vowel에 속해있으면 + 1
            if(check(s[j])){
                temp++;
                //+가 되지 않았는데 굳이 ans값을 갱신할 이유가 없음
                ans = max(ans, temp);
            }                        
        }
        
        return ans;
    }
};