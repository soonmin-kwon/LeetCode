/************************
 * Valid Mountain Array *
 ************************/

public class Solution {
    public bool ValidMountainArray(int[] arr) {
        if(arr.Length <= 2){
            return false;
        }
        
        if(arr[0] > arr[1]){
            return false;
        }
        
        int peekIdx = 0;
        
        for(int i=1; i<arr.Length; ++i){
            if(arr[i] == arr[i-1]){
                return false;
            }
            
            if(arr[i] < arr[i-1]){
                peekIdx = i;
                break;
            }                        
        }
        
        for(int i=peekIdx; i<arr.Length-1; ++i){
            if(arr[i] <= arr[i+1]){
                return false;
            }
        }
        
        return true;
    }
}