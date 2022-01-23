/*********************
 * Sequential Digits *
 *********************/

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int> q{{1,2,3,4,5,6,7,8,9}};
        vector<int> ans;
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            
            if(curr > high){
                break;
            }
            
            if(low <= curr && curr <= high){
                ans.push_back(curr);
            }
            
            int num = curr % 10;
            int nextDigit = curr * 10 + num + 1;
            
            if(num < 9){
                q.push(nextDigit);
            }
        }
        
        return ans;
    }
};