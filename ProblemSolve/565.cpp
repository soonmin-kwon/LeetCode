/*****************
 * Array Nesting *
 *****************/

class Solution {
public:
    //Solution
    //참고 : https://leetcode.com/problems/array-nesting/solution/
    int arrayNesting(vector<int>& nums) {
        int len = nums.size();
        int ans = 0;
        vector<bool> visitied(len);
        
        for(int i=0; i<len; i++){
            //이미 visitied에 체크되어 있으면
            //무조건 기존 ans보다 작을 수 밖에 없다
            if(!visitied[i]){
                int start = nums[i];
                int count = 0;
                
                do{                    
                    start = nums[start];
                    visitied[start] = true;
                    count++;                    
                }while(start != nums[i]);   //사이클인지 확인
                
                ans = max(ans, count);
            }
        }
        
        return ans;
    }
    
    int ans = 0;
    
    //unordered_set으로 중복 확인
    void dfs(vector<int>& nums, unordered_set<int>& set, int idx, vector<bool>& visitied) {
        if(set.find(nums[idx]) != set.end()){
            ans = max(ans, (int)set.size());
            return;
        }
        
        set.insert(nums[idx]);
        visitied[nums[idx]] = true;
        dfs(nums, set, nums[idx], visitied);
        
        return;
    }
    
    int arrayNesting(vector<int>& nums) {
        int len = nums.size();
        unordered_set<int> us;
        vector<bool> visitied(len);
        
        for(int i=0; i<len; i++){
            if(!visitied[nums[i]]){
                dfs(nums, us, nums[i], visitied);
            }            
            if(ans == len){
                break;
            }
            us.clear();
        }
        
        return ans;
    }
};