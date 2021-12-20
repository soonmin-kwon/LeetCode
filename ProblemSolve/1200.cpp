/*******************************
 * Minimum Absolute Difference *
 *******************************/

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int minGap = 2000001;
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        
        //One Pass
        for(int i=0; i<arr.size()-1; ++i){
            int curGap = arr[i+1] - arr[i];
            
            if(curGap == minGap){
                ans.push_back({arr[i], arr[i+1]});
            }
            else if(curGap < minGap){
                ans.clear();
                
                ans.push_back({arr[i], arr[i+1]});
                minGap = curGap;
            }
        }
        
        /*
        Two Pass
        for(int i=0; i<len; ++i){
            minGap = min(minGap, arr[i+1] - arr[i]);
        }
        
        for(int i=0; i<len; ++i){
            if(arr[i+1] - arr[i] == minGap){
                ans.push_back({arr[i],arr[i+1]});
            }
        }*/
        
        return ans;
    }
};