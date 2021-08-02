/*****************
 * Count and Say *
 *****************/

class Solution {
public:
    //재귀 없이 구현    
    string countAndSay(int n) {
        //1이나 2면 바로 리턴한다.
        if(n == 1){
            return  "1";
        }
        
        if(n == 2){
            return "11";
        }
                
        //재귀처럼 진행하기 위해 초기값을 2로잡는다.
        string ans = "11";        
        
        //사용할 변수들 선언
        int len;
        int count;
        char temp;
        string temp2 ="";
        
        //3이상의 값이 인풋으로 들어오면 n까지 차근차근 진행한다.
        for(int j=3; j<=n; j++){
            //현재 문자열의 길이, 시작점의 character값, 빈 문자열, char 카운트
            len = ans.size();
            temp = ans[0];
            temp2 = "";
            count = 1;
            
            //현재 문자열을 기준으로 진행
            for(int i=1; i<len; i++){
                //같으면 count+1
                if(ans[i] == temp){
                    count++;
                }
                //다르면 현재까지 센 카운트에 맞게 문자열에 삽입
                else{
                    temp2 += count + '0';
                    temp2 += temp;
                    count = 1;
                    temp = ans[i];
                    
                }
            }
            
            //마지막을 적용하지 못하고 loop이 끝나기 때문에 추가
            temp2 += count + '0';
            temp2 += temp;
            
            ans = temp2;
        }        
        
        return ans;
    }
};