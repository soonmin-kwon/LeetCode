/*********************************
 * Reduce Array Size to The Half *
 *********************************/

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        //arr 배열에 있는 num들의 frequency를 기준으로 pq정렬
        priority_queue<int, vector<int>> pq;
        //frequency 체크
        unordered_map<int, int> hash;
        
        int ans = 0;
        //목표. 절반 이하만 되면 됨
        int half = arr.size() / 2;
        
        //frequency 체크
        for(int num : arr){
            hash[num]++;
        }
        
        //frquency를 pq에 넣어서 정렬
        for(auto it=hash.begin(); it!=hash.end(); it++){
            pq.push(it -> second);
        }
        
        //더 줄여야 하면서 queue가 비어있지 않으면 while문을 돈다
        while(!pq.empty() && half > 0){
            ans++;
            half -= pq.top();
            pq.pop();
        }
        
        return ans;
    }
};