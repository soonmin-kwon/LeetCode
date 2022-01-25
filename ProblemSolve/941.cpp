/************************
 * Valid Mountain Array *
 ************************/

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int len = arr.size();
        int peekIdx = 0;
        
        if(len <= 2){
            return false;
        }
        
        if(arr[0] > arr[1]){
            return false;
        }
        
        for(int i=1; i<len; ++i){
            if(arr[i] == arr[i-1]){
                return false;
            }
            
            if(arr[i] < arr[i-1]){
                peekIdx = i-1;
                break;
            }
        }
        
        for(int i=peekIdx; i<len-1; ++i){
            if(arr[i] <= arr[i+1]){
                return false;
            }
        }
        
        return true;
    }
};