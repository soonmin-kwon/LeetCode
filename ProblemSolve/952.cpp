/*******************************************
 * Largest Component Size by Common Factor *
 *******************************************/

class Solution {
public:
     vector<int> parent;

    int findParent(int x){
        if(parent[x] == x){
            return x;
        }
        else{
            return parent[x] = findParent(parent[x]);
        }
    }

    void unionNode(int x, int y){
        x = findParent(x);
        y = findParent(y);

        if(x != y){
            parent[y] = x;
        }
    }

    int largestComponentSize(vector<int>& nums) {
        int maxEle = *max_element(nums.begin(), nums.end());
        
        parent.resize(maxEle + 1);
        
        for(int i=0; i<=maxEle; i++){
            parent[i] = i;
        }
        
        //같은 약수를 가지면 Union
        for(int i=0; i<nums.size(); i++){
            for(int j=2; j<=sqrt(nums[i]); j++){
                if(nums[i] % j == 0){
                    unionNode(nums[i], j);
                    unionNode(nums[i], nums[i]/j);
                }
            }
        }
        
        vector<int> count(maxEle + 1);        
        int ans = 1;
        
        //같은 부모를 가지는 그래프의 최대 길이 구하기
        for(int num : nums){
            count[findParent(num)]++;
            ans = max(ans, count[findParent(num)]);
        }
        
        return ans;
    }
};