/*******************************
 * Interval List Intersections *
 *******************************/

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;
        vector<int> temp(2);
        int idxFirstList = 0, idxSecondList = 0;
        int lenFirstList = firstList.size(), lenSecondList = secondList.size();
        
        while(idxFirstList < lenFirstList && idxSecondList < lenSecondList){
            int startPoint = max(firstList[idxFirstList][0], secondList[idxSecondList][0]);
            int endPoint = min(firstList[idxFirstList][1], secondList[idxSecondList][1]);
            
            if(startPoint <= endPoint){
                temp[0] = startPoint;
                temp[1] = endPoint;
                
                ans.push_back(temp);
            }
            
            if(endPoint == firstList[idxFirstList][1]){
                ++idxFirstList;
            }
            else{
                ++idxSecondList;
            }
        }
        
        return ans;
    }
};