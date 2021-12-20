/*******************************
 * Minimum Absolute Difference *
 *******************************/

public class Solution {
    public IList<IList<int>> MinimumAbsDifference(int[] arr) {
        Array.Sort(arr);
        int minGap = 2000001;
        List<IList<int>> ans = new List<IList<int>>();
        
        for(int i=0; i<arr.Length-1; ++i){
            minGap = Math.Min(minGap, arr[i+1] - arr[i]);
        }
        
        for(int i=0; i<arr.Length-1; ++i){
            if(arr[i+1] - arr[i] == minGap){
                List<int> elements = new List<int>();
                elements.Add(arr[i]);
                elements.Add(arr[i+1]);
                ans.Add(elements);
            }
        }
        
        return ans;
    }
}