/*******************************************
 * Largest Component Size by Common Factor *
 *******************************************/

public class Solution {
    int[] parent;
    
    public int findParent(int x){
        if(parent[x] == x){
            return x;
        }
        else{
            return parent[x] = findParent(parent[x]);
        }
    }
    
    public void unionNode(int x, int y){
        x = findParent(x);
        y = findParent(y);
        
        if(x != y){
            parent[y] = x;
        }
    }
    
    public int LargestComponentSize(int[] nums) {
        int maxElement = 0;
        
        foreach(int num in nums){
            maxElement = Math.Max(maxElement, num);
        }
        
        Array.Resize(ref parent, maxElement+1);
        
        for(int i=0; i<=maxElement; ++i){
            parent[i] = i;
        }
        
        foreach(int num in nums){
            for(int j=2; j<=Math.Sqrt(num); ++j){
                if(num % j == 0){
                    unionNode(num, j);
                    unionNode(num, num/j);
                }
            }
        }
        
        int[] count = new int[maxElement + 1];
        int ans = 1;
        
        foreach(int num in nums){
            ans = Math.Max(ans, ++count[findParent(num)]);
        }
        
        return ans;
    }
}