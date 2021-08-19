/************************
 * Top K Frequent Words *
 ************************/

class Solution {
public:
    //priority_queue 정렬 구조체
    struct Compare{
        //count가 높은 순으로 정렬
        //count가 같으면 string 사전순으로 정렬
        bool operator() (const pair<int, string>& a, const pair<int, string> b) {            
            if(a.first == b.first){
                return a.second > b.second;
            }
                        
            return a.first < b.first;
        }
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> map;
        vector<string> ans;
        
        //map에 개수 카운트
        for(int i=0; i<words.size(); i++){
            map[words[i]]++;
        }
        
        priority_queue<pair<int, string>, vector<pair<int,string>>, Compare> pq;
        
        //map에 들어있는 element들 priority_queue에 입력
        for(auto it = map.begin(); it!=map.end(); it++){
            pq.push(make_pair(it->second, it->first));
        }
        
        //k개 만큼 priority_queue에서 꺼낸다
        for(int i=0; i<k; i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};