/**************************
 * Array of Doubled Pairs *
 **************************/

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {        
        //절대값 기준 정렬
        sort(arr.begin(), arr.end(), [](const int& a, const int& b) {
                                        return abs(a)  < abs(b);
                                        });
        
        int len = arr.size();
        unordered_map<int,int> map;
        
        //map에 각 요소 카운트
        for(int i=0; i<len; i++){
            map[arr[i]] += 1;
        }
        
        for(int i=0; i<len; i++){
            //0이면 스킵 
            if(map[arr[i]] == 0){
                continue;
            }
            
            //현재 원소의 2배 값이 있는지 확인 없으면 바로 리턴
            if(map.find(2 * arr[i]) != map.end() && map[arr[i]] > 0 && map[2*arr[i]] > 0){
                map[arr[i]] -=1;
                map[2*arr[i]] -=1;
            }
            else{
                return false;
            }
        }
        
        return true;
    }
};