/****************************
 * Remove Covered Intervals *
 ****************************/

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
    
    public int RemoveCoveredIntervals(int[][] intervals) {
        int ans = 0;
        int left = -1, right = -1;
        
        QuickSort(ref intervals, 0, intervals.Length-1);
        
        foreach(var interval in intervals){
            if(interval[0] > left && interval[1] > right){
                left = interval[0];
                ans++;
            }
            
            right = Math.Max(right, interval[1]);
        }
        
        return ans;
    }
}