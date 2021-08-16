/********************************************
 * Kids With the Greatest Number of Candies *
 ********************************************/

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {        
        int len = candies.size();
        vector<bool> ans;
        int maxCandy = -1;
        
        //가장 큰 원소 찾는다
        for(int i=0; i<len; i++){
            maxCandy = max(maxCandy, candies[i]);
        }
        
        //가장 큰 원소를 기준으로 크면 true
        for(int i=0; i<len; i++){
            if(candies[i] + extraCandies >= maxCandy){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        
        return ans;
    }
};