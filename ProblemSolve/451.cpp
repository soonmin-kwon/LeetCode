/********************************
 * Sort Characters By Frequency *
 ********************************/

//참고 : https://www.cplusplus.com/reference/string/string/string/

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> frequency;         //어떤 char의 frequency를 저장
        priority_queue<pair<int,char>> heap;        //위에서 구한 frequency를 기준으로 정렬
        string ans = "";
        
        //frequency를 구한다
        for(char ch : s){
            frequency[ch]++;
        }
        
        //heap에 넣으면 자동으로 반복 회수로 내림차순 정렬된다
        for(auto it = frequency.begin(); it != frequency.end(); it++){
            heap.push(make_pair(it->second, it->first));
        }
        
        //heap에 들어있는 만큼 정답 문자열에 추가한다.
        while(!heap.empty()){
            ans += string(heap.top().first, heap.top().second);
            heap.pop();
        }
        
        return ans;        
    }
};