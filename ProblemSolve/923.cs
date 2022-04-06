/**************************
 * 3Sum With Multiplicity *
 **************************/

public class Solution {
    public int ThreeSumMulti(int[] arr, int target) {
        Dictionary<int, int> hash = new Dictionary<int, int>();
        
        int ans = 0, mod = (int)1e9 + 7;
        
        for(int i=0; i<arr.Length; ++i){
            if(hash.TryGetValue(target - arr[i], out int val))
                ans = (ans + val) % mod;
            
            for(int j=0; j<i; ++j){
                if(!hash.TryGetValue(arr[i] + arr[j], out val))
                    hash[arr[i] + arr[j]] = 1;
                else
                    hash[arr[i] + arr[j]]++;
            }
        }
        
        return ans;
    }
}