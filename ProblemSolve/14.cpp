/*************************
 * Longest Common Prefix *
 *************************/

class Solution {
public:        
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        //abc 순으로 정렬
        sort(strs.begin(), strs.end());                
        
        int len1 = strs.size();
        string first = strs[0];
        string last = strs[len1 - 1];
        
        int len2 = first.size();                
        
        //정렬을 했기 때문에 가장 뒤에 있는 문자열하고만 비교하면 찾아낼 수 있다.
        for(int i=0; i<len2; i++){            
            if(first[i] == last[i]){
                ans += first[i];
            }else{
                break;
            }
        }
                
        return ans;
    }    
};