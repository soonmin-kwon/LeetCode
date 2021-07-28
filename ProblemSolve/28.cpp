/**********************
 * Implement strStr() *
 **********************/

//KMP 알고리즘
//참고 https://bowbowbow.tistory.com/6

class Solution {
public:
    
    vector<int> getPi(string& s){
        int m = s.size();
        int j = 0;
        vector<int> pi(m,0);
        for(int i=1; i<m; i++){
            while(j > 0 && s[i] != s[j]){
                j = pi[j-1];
            }
            
            if(s[i] == s[j]){
                pi[i] = ++j;
            }
        }
        return pi;
    }
    
    int strStr(string haystack, string needle) {        
        int count = 0;
        int lenHay = haystack.size();
        int lenNeedle = needle.size();                
        if(lenNeedle == 0){
            return 0;
        }
        
        if(lenNeedle > lenHay){
            return -1;
        }        
        
        vector<int> pi = getPi(needle);
        
        for(int i=0; i<lenHay; i++){
            while(count > 0 && haystack[i] != needle[count]){
                count = pi[count-1];
            }
            
            if(haystack[i] == needle[count]){
                if(count == lenNeedle - 1){
                    return i - lenNeedle + 1;
                }else{
                    count++;
                }
            }
        }
        
        return -1;
    }
};