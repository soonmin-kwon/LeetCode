/****************
 * Jump Game IV *
 ****************/

public class Solution {
    public int MinJumps(int[] arr) {
        int len = arr.Length-1;
        int ans = 0;
        
        Queue<int> q = new Queue<int>();
        bool[] visitied = new bool[len+1];
        Dictionary<int, List<int>> hash = new Dictionary<int,List<int>>();
        
        for(int i=0; i<=len; ++i){
            if(!hash.ContainsKey(arr[i])){
                hash.Add(arr[i], new List<int>());
            }
            hash[arr[i]].Add(i);
        }
        
        q.Enqueue(0);
        visitied[0] = true;
        
        while(q.Count > 0){
            for(int i=q.Count; i>0; --i){
                int idx = q.Dequeue();
                
                if(idx == len){
                    return ans;
                }
                
                var canJump = hash[arr[idx]];
                canJump.Add(idx-1);
                canJump.Add(idx+1);
                
                foreach(var next in canJump){
                    if(0 <= next && next <= len && !visitied[next]){
                        q.Enqueue(next);
                        visitied[next] = true;
                    }
                }
                
                canJump.Clear();
            }
            
            ++ans;
        }
        
        return 0;
    }
}