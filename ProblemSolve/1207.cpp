/********************************
 * Unique Number of Occurrences *
 ********************************/

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        //각 arr의 element를 카운트
        unordered_map<int,int> hash;
        //각 arr의 element의 개수가 unique한지
        unordered_set<int> us;
        int len = arr.size();
        int count = 0;
        
        //각 element 카운트
        for(int i=0; i<len; i++){
            hash[arr[i]] += 1;
        }
        
        //unique한지 확인하기 위해 카운트를 set에 삽입
        for(auto it=hash.begin(); it!=hash.end(); it++){
            us.insert(it->second);
        }
        
        //set의 크기와 hash의 크기가 같으면 모든 element의 개수가 unique한 경우
        return (us.size() == hash.size()) ? true : false;
    }
};