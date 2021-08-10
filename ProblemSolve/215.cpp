/***********************************
 * Kth Largest Element in an Array *
 ***********************************/

class Solution {
public:
    //map 이용
    int findKthLargest3(vector<int>& nums, int k) {
        map<int,int> count;
        
        int len = nums.size();
        
        //key의 value를 올려서 카운트
        for(int i=0; i<len; i++){
            count[nums[i]] += 1;
        }
        
        int temp = 0;
        
        //k번째로 큰 key 값을 찾아야 하기 때문에 map의 뒤에서부터 서치
        //val이 개수를 뜻하므로 개수만큼 더하면서 k보다 크거나 같아지면 그 key값이 찾고자 하는 정답
        for(auto it = --count.end(); it!= count.begin(); it--){
            temp += it->second;            
            if(temp >= k){
                return it->first;
            }
        }
        
        //위 for문에서 못 찾으면 제일 뒤에 앞에 있는 값이 정답
        return count.begin() -> first;
    }
    
    //priority queue 이용
    int findKthLargest2(vector<int>& nums, int k) {
        priority_queue<int, vector<int>> q;
        
        int len = nums.size();
        
        //모든 값을 q에 삽입
        for(int i=0; i<len; i++){
            q.push(nums[i]);
        }
        
        //k번째로 큰 값을 찾는다
        for(int i=1; i<k; i++){
            q.pop();
        }
        
        return q.top();
    }
    
    //sort 이용
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        
        return nums[nums.size() - k];
    }
};