/*******************
 * Merge Intervals *
 *******************/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;        
        //시작점을 기준으로 정렬
        sort(intervals.begin(), intervals.end());
        
        int len = intervals.size();
        //제일 처음이 되는 값들 push_back
        ans.push_back({intervals[0][0], intervals[0][1]});
        
        for(int i=1; i<len; i++){
            //끝나는 시간이 시작 시간보다 작으면
            //정상적으로 다음 값이 들어와야 한다
            if(ans.back()[1] < intervals[i][0]){
                ans.push_back({intervals[i][0], intervals[i][1]});
            }
            //끝나는 시간이 다음 시작시간과 겹치면
            //현재 끝나는 시간과 들어올 끝나는 시간을 비교해 큰 값을 넣어준다
            else{
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }
        
        return ans;
    }
};