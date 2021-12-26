/******************************
 * K Closest Points to Origin *
 ******************************/

public class Solution {
    public void Swap(ref int[] a, ref int[] b){
        int[] temp = a;
        a = b;
        b = temp;
    }

    public void QuickSort(ref int[][] points, int start, int end){
        if(start >= end){
            return;
        }

        ref int[] pivot = ref points[end];
        int left = start;
        int right;

        for(right = start; right<end; ++right){
            int dist1 = points[right][0] * points[right][0] + points[right][1] * points[right][1];
            int dist2 = pivot[0] * pivot[0] + pivot[1] * pivot[1];
            
            if(dist1 < dist2){
                Swap(ref points[right], ref points[left]);
                ++left;
            }
        }
        
        Swap(ref points[left], ref pivot);

	    QuickSort(ref points, left + 1, end);
	    QuickSort(ref points, start, left - 1);

	    return;
    }
    
    public int[][] KClosest(int[][] points, int k) {
        //Sorting
        QuickSort(ref points, 0, points.Length-1);
        
        Array.Resize(ref points, k);
        
        return points;
        
        //LinQ
        //return points.OrderBy(x => x[0] * x[0] + x[1] * x[1]).Take(k).ToArray();
    }
}