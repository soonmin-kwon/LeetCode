/*************************************
 * Numbers At Most N Given Digit Set *
 *************************************/

//참고 : https://leetcode.com/problems/numbers-at-most-n-given-digit-set/solution/

class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string given = to_string(n);
        int len = given.size();
        int digitSize = digits.size();
        
        vector<int> dp(len + 1);
        dp[len] = 1;
        
        for(int i=len-1; i>=0; i--){
            int givensDigit = given[i] - '0';
            for(string digit : digits){
                if(stoi(digit) < givensDigit){
                    dp[i] += pow(digitSize, len - i - 1);
                }
                else if(stoi(digit) == givensDigit){
                    dp[i] += dp[i+1];
                }
            }
        }
        
        for(int i=1; i<len; i++){
            dp[0] += pow(digitSize, i);
        }
        
        return dp[0];
    }
};