/********************
 * Partition Labels *
 ********************/

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int last[26] = {0, };
        
        for(int i=0; i<s.size(); ++i){
            last[s[i] - 'a'] = i;
        }
        
        int lastIdx = 0, anchor = 0;
        vector<int> ans;
        
        for(int i=0; i<s.size(); ++i){
            lastIdx = max(lastIdx, last[s[i] - 'a']);
            
            if(i == lastIdx){
                ans.push_back(i - anchor + 1);
                anchor = i + 1;
            }
        }
        
        return ans;
    }
};