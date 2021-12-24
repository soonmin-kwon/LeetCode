/*******************
 * Merge Intervals *
 *******************/

public class Solution {
    public void Swap(ref int[] a, ref int[] b){
        int[] temp = a;
        a = b;
        b = temp;
    }
    
    public void QuickSort(ref int[][] intervals, int start, int end){
        if(start >= end){
            return;
        }
        
        ref int[] pivot = ref intervals[end];
        int left = start;
        int right;
        
        for(right = start; right<end; ++right){
            if(intervals[right][0] < pivot[0]){
                Swap(ref intervals[right], ref intervals[left]);
                ++left;
            }
        }
        Swap(ref intervals[left], ref pivot);

	    QuickSort(ref intervals, left + 1, end);
	    QuickSort(ref intervals, start, left - 1);

	    return;
    }
    
    public int[][] Merge(int[][] intervals) {
        List<int[]> ans = new List<int[]>();
        int len = intervals.Length;
        
        QuickSort(ref intervals, 0, len-1);     //intervals = intervals.OrderBy(x => x[0]).ToArray();
        
        ans.Add(new int[2]{intervals[0][0], intervals[0][1]});
        
        for(int i=1; i<len; ++i){
            //새로운 범위 정답에 추가
            if(ans[ans.Count-1][1] < intervals[i][0]){
                ans.Add(new int[2]{intervals[i][0], intervals[i][1]});
            }
            //범위가 겹치면 합치기
            else{
                ans[ans.Count-1][1] = Math.Max(intervals[i][1], ans[ans.Count-1][1]);
            }
        }
                                              
        return ans.ToArray();
    }
}