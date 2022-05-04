/*****************************
 * Max Number of K-Sum Pairs *
 *****************************/

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        int ans = 0;
        
        for(int& i : nums){
            hash[i]++;
        }
        
        for(auto it=hash.begin(); it!= hash.end(); it++){
            int num = it -> first;
            int count = it -> second;
            
            if(k - num == num){
                ans += count / 2;
            }
            else if(hash.find(k - num) != hash.end()){
                int minimum = min(count, hash[k-num]);
                ans += minimum;
                
                hash[num] -= minimum;
                hash[k-num] -= minimum;
            }
        }
        
        return ans;
    }
};