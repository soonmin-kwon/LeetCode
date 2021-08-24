/******************
 * Is Subsequence *
 ******************/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        //hash table
        unordered_map<char, vector<int>> hash;
        
        int len = t.size();
        //t의 idx와 char값 저장
        //idx순으로 저장되므로 정렬되어있음
        for(int i=0; i<len; i++){
            hash[t[i]].push_back(i);
        }
        
        int prev = -1;
        len = s.size();
        vector<int> v;
        
        for(int i=0; i<len; i++){
            //찾으려는 값이 없으면 리턴 false
            auto it = hash.find(s[i]);
            if(it == hash.end()){
                return false;
            }
            
            v = it->second;
            
            //이전값보다 큰 값을 찾는다
            //s가 t의 subsequence가 되려면 순서도 맞아야한다
            //ex) s = "ace", t = "abcde"일땐 true, s = "aec", t = "abcde"일땐 false
            auto it2 = upper_bound(v.begin(), v.end(), prev);
            
            //그 값이 없으면 리턴 false
            if(it2 == v.end()){
                return false;
            }
            
            //prev값 최신화
            prev = *it2;
        }
        
        return true;
    }
};