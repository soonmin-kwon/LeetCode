/********************************************************
 * Replace Elements with Greatest Element on Right Side *
 ********************************************************/

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int prev = arr.back();
        int len = arr.size();
        int temp;
        
        //오른쪽부터 진행
        for(int i=len - 2; i>= 0; i--){
            temp = arr[i];
            arr[i] = prev;
            //prev 값과 현재 값중에 더 큰 값을 prev 값으로 저장
            prev = max(temp, prev);            
        }
        
        //끝 값 수정
        arr[len -1] = -1;
        
        return arr;
    }    
};