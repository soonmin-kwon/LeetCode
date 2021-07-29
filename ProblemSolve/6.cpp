/*********************
 * ZigZag Conversion *
 *********************/

// numRows에 따라 인덱싱 하는 규칙이 바뀐다.
// ex) numRows = 4 -> 0, 6, 12 ..., 1, 5, 7, 11, 13..., 2, 4, 8, 10, 14, ..., 3, 9, 15, ...
// idx로 몇번째 줄인지 나타내면서 각 줄마다 바뀌는 규칙을 적용한다. ** 0이 첫째 줄 **
// 첫 줄과 마지막 줄은 하나의 stride로 표현 할 수 있기 때문에 따로 loop을 돌고,
// 나머지 줄들은 두 stride, 내려가는 stride, 올라가는 stride를 사용하면서 원래 문자열에 인덱싱한다.

// 내려가는 경우
// n번째 줄은 numRows - 2 - n 만큼 내려가고 마지막 줄을 거쳐 numRows - 2 - n 만큼 올라오고 다음 index에 접근한다.
// 따라서 내려가는 stride는 numRows - 2 -idx + numRows -2 + idx + 2 = 2 * (numRows - 1 - idx)

// 올라가는 경우
// 첫째 줄을 제외한 줄에서 stride는 (idx - 1) 만큼 올라가고 첫번째 줄을 거쳐 idx -1 만큼 내려오고 다음 index에 접근한다.
// 따라서 올라가는 stride는 idx -1 + idx -1 + 1 = 2*(idx + 1)이다.

// 첫번째 줄은 올라가지 못하고 마지막 줄은 내려가지 못하기 때문에 하나의 stride만 사용하고
// 마지막 줄의 경우 첫째 줄에서 내려가는 만큼 올라오기 때문에 같은 stride를 사용한다.

class Solution {
public:
    string convert(string s, int numRows) {
        // 인풋의 길이가 1이면 변환 필요 x
        if(numRows == 1){
            return s;
        }
        
        int max = s.size();
        int idx = 0;
        
        int stride = 2 * (numRows - 1);
        string ans = "";
        
        //첫번째 줄 완성, stride만큼 넘어간다.
        for(int i=idx; i<max; i+=stride){
            ans += s[i];
        }        
        
        // 두번째 줄부터 마지막 전 줄 완성
        while(idx != numRows - 2){
            idx++;
            for(int i= idx; i<max;){
                ans += s[i];
                //내려가기
                i += stride - (2*idx);
                // stride의 범위가 max, 즉 s의 길이를 넘어서면, indexing하지 못하면 break;
                if( i >= max ){
                    break;
                }
                //올라오기
                ans += s[i];
                i += 2*idx;
            }            
        }        
        
        //마지막 줄 완성
        for(int i= idx + 1; i<max; i+=stride){
            ans += s[i];
        }        
        
        return ans;        
    }
};