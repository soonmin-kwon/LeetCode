/***************************
 * Top K Frequent Elements *
 ***************************/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int len = nums.size();
                
        if(k == len){
            return nums;
        }
        
        unordered_map<int,int> count;
        
        //nums에 들어있는 개수 세기
        for(int i=0; i<len; i++){
            count[nums[i]] += 1;
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>> q;
        //priority queue에 개수대로 정렬되도록 삽입
        for(auto it = count.begin(); it!=count.end(); it++){
            q.push({it-> second, it->first});
        }
        
        vector<int> ans;
        
        //제일 앞에 있는 k개 만큼 정답에 추가
        for(int i=0; i<k; i++){
            ans.push_back(q.top().second);
            q.pop();
        }
        
        return ans;
    }
};