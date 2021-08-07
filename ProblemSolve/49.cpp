/******************
 * Group Anagrams *
 ******************/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int len = strs.size();
        
        if(len == 1){
            return {{strs[0]}};
        }
        
        string temp;
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> map;
        
        for(int i=0; i<len; i++){
            //저장
            temp = strs[i];
            //정렬
            sort(strs[i].begin(), strs[i].end());
            //같은 스펠링을 갖고 있는 문자들을 벡터에 저장
            map[strs[i]].push_back(temp);                
        }
        
        for(auto it = map.begin(); it!=map.end(); it++){
            ans.push_back(it -> second);
        }
        
        return ans;
    }
        
};