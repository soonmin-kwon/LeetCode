/******************************
 * Longest Turbulent Subarray *
 ******************************/

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int len = arr.size();
        int ans = 1;
        
        int bigger = 1;     //현재 값이 큰 값 차례일 때 최대 길이
        int smaller = 1;    //현재 값이 작은 값 차례일 때 최대 길이
        
        for(int i=1; i<len; i++){
            if(arr[i] > arr[i-1]){
                //현재 값이 큰 값 차례이면 arr[i-1]번째 값이 작은 값 차례일 때 가지는 최대 길이를 늘려나감
                bigger = smaller + 1;
                //subarray를 구하는 것이기 때문에 초기화 된다
                smaller = 1;
            }
            else if(arr[i] < arr[i-1]){
                //현재 값이 작은 값 차례이면 arr[i-1]번째 값이 큰 값 차례일 때 가지는 최대 길이를 늘려나감
                smaller = bigger + 1;
                //subarray를 구하는 것이기 때문에 초기화 된다
                bigger = 1;                
            }
            else{
                //subarray를 구하는 것이기 때문에 초기화 된다
                bigger = 1;
                smaller = 1;
            }
            
            //최대값 지속 갱신
            ans = max({ans, bigger, smaller});
        }

        return ans;
    }
};