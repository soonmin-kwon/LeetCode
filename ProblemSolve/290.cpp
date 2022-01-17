/****************
 * Word Pattern *
 ****************/

class Solution {
public:
    vector<string> split(string input, char token){
        vector<string> splitted;
        stringstream ss(input);
        string temp;
        
        while(getline(ss, temp, token)){
            splitted.push_back(temp);
        }
        
        return splitted;
    }
    
    bool wordPattern(string pattern, string s) {
        unordered_map<string, char> hash;
        unordered_map<char, string> hash2;
        vector<string> splitted = split(s, ' ');
        
        if(pattern.size() != splitted.size()){
            return false;
        }
        
        for(int i=0; i<splitted.size(); ++i){
            if(hash.find(splitted[i]) != hash.end() && hash[splitted[i]] != pattern[i]){
                return false;
            }
            
            hash[splitted[i]] = pattern[i];
            
            if(hash2.find(pattern[i]) != hash2.end() && hash2[pattern[i]] != splitted[i]){
                return false;
            }
            
            hash2[pattern[i]] = splitted[i];
        }
        
        return true;
    }
};