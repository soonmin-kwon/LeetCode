/*******************************
 * Interval List Intersections *
 *******************************/

public class Solution {
    public int[][] IntervalIntersection(int[][] firstList, int[][] secondList) {
        List<int[]> ansTemp = new List<int[]>();
        
        int idxFirstList = 0, idxSecondList = 0;
        
        //겹치는 부분을 찾는다
        //더 느린 시작점, 더 빠른 끝점을 찾아서 정답에 추가한다
        //범위를 벗어난 interval이 있으면 다음 interval을 확인한다
        while(idxFirstList < firstList.Length && idxSecondList < secondList.Length){
            int startPoint = Math.Max(firstList[idxFirstList][0], secondList[idxSecondList][0]);
            int endPoint = Math.Min(firstList[idxFirstList][1], secondList[idxSecondList][1]);
            
            if(startPoint <= endPoint){
                ansTemp.Add(new int[]{startPoint, endPoint});
            }
            
            //다음 interval 확인
            if(endPoint == firstList[idxFirstList][1]){
                ++idxFirstList;
            }
            else{
                ++idxSecondList;
            }
        }
        
        int[][] ans = new int[ansTemp.Count][];
        int idx = 0;
        
        foreach(var interval in ansTemp){
            ans[idx] = interval;
            ++idx;
        }
        return ans;
    }
}