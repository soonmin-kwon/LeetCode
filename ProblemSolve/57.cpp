/*******************
 * Insert Interval *
 *******************/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        
        //newInterval과 겹치는 부분을 확인하면서 newInterval을 수정해나간다
        for(int i=0; i<intervals.size(); i++){            
            //newInterval이 시작되기 전에 끝나는 interval은 그냥 정답에 추가
            if(intervals[i][1] < newInterval[0]){
                ans.push_back(intervals[i]);
            }
            //newInterval이 온전하게 들어갈 수 있으면 newInterval을 정답에 추가
            else if(intervals[i][0] > newInterval[1]){
                ans.push_back(newInterval);
                newInterval = intervals[i];
            }
            //newInterval이 intervals[i]와 겹치는 경우 newInterval의 범위를 넓혀서 더 큰 interval을 만든다
            else if(intervals[i][1] >= newInterval[0] || intervals[i][0] <= newInterval[1]){
                newInterval[0] = min(intervals[i][0], newInterval[0]);
                newInterval[1] = max(intervals[i][1], newInterval[1]);
            }                        
        }
        
        ans.push_back(newInterval);
        
        return ans;
    }
};