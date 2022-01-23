/*********************
 * Sequential Digits *
 *********************/

public class Solution {
    public IList<int> SequentialDigits(int low, int high) {
        Queue<int> q = new Queue<int>(new[] {1, 2, 3, 4, 5, 6, 7, 8, 9});
        
        List<int> ans = new List<int>();
        
        while(q.Count > 0){
            int curr = q.Dequeue();
            if(curr > high){
                break;
            }
            
            if(low <= curr && curr <= high){
                ans.Add(curr);
            }
            
            int num = curr % 10;
            int next = curr * 10 + num + 1;
            
            if(num < 9){
                q.Enqueue(next);
            }
        }
        
        return ans;
    }
}