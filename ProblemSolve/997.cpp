/***********************
 * Find the Town Judge *
 ***********************/

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> counts(n+1);
        
        //한번 다른 사람을 믿으면 town judge가 될 수 없음
        for(auto temp : trust){
            counts[temp[0]]--;
            counts[temp[1]]++;
        }
        
        for(int i=1; i<=n; i++){
            if(counts[i] == n-1){
                return i;
            }
        }
        
        return -1;
    }
};