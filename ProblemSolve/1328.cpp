/**********************
 * Break a Palindrome *
 **********************/

class Solution {
public:
    string breakPalindrome(string palindrome) {
        int len = palindrome.size();
        
        //주어진 문자열의 길이가 1이면 빈 문자열을 리턴
        if(len == 1){
            return "";
        }
        
        //사전적으로 가장 앞에 있어야 하므로
        //중간까지 진행하면서 a가 없으면 바꿔준다
        //palindrome이기 때문에 palindrome[0] == palindrome[len - 1]이고
        //이 루프를 전부 다 돌아도 정답이 나오지 않았다면 palindrome[len - 1]을 
        //b로 바꿔서 사전적으로 가장 앞에 있는 문자열로 만든다
        for(int i=0; i<len/2; i++){
            if(palindrome[i] != 'a'){
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        
        palindrome[len - 1] = 'b';
        
        return palindrome;
    }
};