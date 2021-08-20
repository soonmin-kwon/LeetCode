/************************
 * Reordered Power of 2 *
 ************************/

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        int temp = 1;
        string key;
        //입력 integer를 string으로 변환
        string input = to_string(n);
        //정렬
        sort(input.begin(), input.end());
        
        while(temp < 999999999){
            //2의 거듭제곱을 string으로 바꿔서 정렬한다
            key = to_string(temp);
            sort(key.begin(), key.end());
            
            //만약 n이 2의 거듭제곱으로 표현이 가능하다면 key와 input은 정렬을 했기 때문에 같아야 한다
            if(input == key){
                return true;
            }
            
            temp *= 2;
        }                
        
        return false;
    }
};