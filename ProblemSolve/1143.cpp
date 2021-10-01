/******************************
 * Longest Common Subsequence *
 ******************************/

class Solution {
public:
    //LCS 알고리즘
    int longestCommonSubsequence(string text1, string text2) {
        short len1 = text1.size();
        short len2 = text2.size();
        
        vector<vector<short>> lcs(len1 + 1, vector<short>(len2 + 1));
        
        for(int i=1; i<=len1; i++){
            for(int j=1; j<=len2; j++){
                if(text1[i - 1] == text2[j - 1]){
                    lcs[i][j] = lcs[i-1][j-1] + 1;
                }
                else{                    
                    lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
                }
            }
        }
        
        return lcs[len1][len2];
    }
};