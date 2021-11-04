/*********************
 * Palindrome Number *
 *********************/

public class Solution {
    public bool IsPalindrome(int x) {
        //10, 100, 1000같은 특이케이스 처리
        if(x < 0 ||(x % 10 == 0 && x != 0)){
            return false;
        }
        
        int firstHalfOfX = 0;       //x가 2n + 1자리수면 firstHalfOfX의 자리수는 n + 1이다
        
        //x를 반으로 자른다
        //firstHalfOfX는 x의 앞의 절반이 되고, x는 뒤의 절반만 남게된다.
        while(x > firstHalfOfX){
            firstHalfOfX = firstHalfOfX * 10 + x % 10;
            x/=10;
        }
        
        //firstHalfOfX가 더 긴 경우에는 x의 자리수가 홀수인 경우
        //중간의 한 수를 제외하고 같아야 하므로 10을 나눠서 확인
        return firstHalfOfX == x || firstHalfOfX / 10 == x;
    }
}