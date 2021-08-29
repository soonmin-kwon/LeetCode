/*****************************************
 * Minimum Add to Make Parentheses Valid *
 *****************************************/

class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0;
        //괄호의 균형이 맞는지 확인
        int checkBal = 0;
        int len = s.size();
        
        //모든 element 순회
        for(int i=0; i<len; i++){
            //만약 s[i]가 ( 면 checkBal + 1, )면 checkBal - 1
            checkBal += s[i] == '(' ? 1 : -1;
            
            //checkBal이 -1이 되면 여는 괄호가 부족한 것이기 때문에
            //여는 괄호 한개 삽입한 것처럼 checkBal + 1, ans + 1
            if(checkBal == -1){
                ans++;
                checkBal++;
            }
        }
        
        //여는 괄호만 있는 경우 닫는 괄호를 추가해줘야 하기때문에 열려있는 괄호만큼 정답에 추가
        ans+= checkBal;
        
        return ans;
    }
};