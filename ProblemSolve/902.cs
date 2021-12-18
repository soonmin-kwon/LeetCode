/*************************************
 * Numbers At Most N Given Digit Set *
 *************************************/

//참고 : https://leetcode.com/problems/numbers-at-most-n-given-digit-set/solution/
public class Solution {
    public int AtMostNGivenDigitSet(string[] digits, int n) {
        string given = n.ToString();
        int len = given.Length;
        
        int[] dp = new int[len + 1];
        dp[len] = 1;
        
        for(int i=len-1; i>=0; --i){
            int givenDigit = given[i]-'0';
            foreach(string digit in digits){
                //더 작은 수이면 길이의 제곱 만큼 개수가 증가
                if(int.Parse(digit) < givenDigit){
                    dp[i] += (int)Math.Pow(digits.Length, len - i - 1);
                }
                //같은 수면 그대로 증가
                else if(int.Parse(digit) == givenDigit){
                    dp[i] += dp[i+1];
                }
            }
        }
        
        for(int i=1; i<len; ++i){
            dp[0] += (int)Math.Pow(digits.Length, i);
        }
        
        return dp[0];
    }
}