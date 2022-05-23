/******************
 * One and Zeroes *
 ******************/

public class Solution {
    public int count(string str, char ch){
        int result = 0;
        
        for(int i=0; i<str.Length; ++i){
            if(str[i] == ch){
                result++;
            }
        }
        
        return result;
    }
    
    public int FindMaxForm(string[] strs, int m, int n) {
        int[,] dp = new int[m+1, n+1];
        
        int zeroCount = 0, oneCount = 0;
        
        foreach(var str in strs){
            zeroCount = count(str, '0');
            oneCount = str.Length - zeroCount;
            
            for(int i=m; i >= zeroCount; --i){
                for(int j=n; j >= oneCount; --j){
                    dp[i,j] = Math.Max(dp[i,j], dp[i-zeroCount, j-oneCount] + 1);
                }
            }
        }
        
        return dp[m,n];
    }
}