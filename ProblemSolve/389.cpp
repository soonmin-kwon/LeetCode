/***********************
 * Find the Difference *
 ***********************/

class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> hash;
        
        for(char c : s){
            hash[c]++;
        }
        
        for(char c : t){            
            hash[c]--;
            if(hash[c] < 0){
                return c;
            }
        }
        
        return ' ';
    }
};