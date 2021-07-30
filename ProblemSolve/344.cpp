/******************
 * Reverse String *
 ******************/

class Solution {
public:
    void reverseString(vector<char>& s) {
        //비어있으면 리턴
        if(s.empty()){
            return;
        }
        
        int len = s.size();
        //swap 함수로 바꾸기
        for(int i=0; i<len/2; i++){
            swap(s[i], s[len -1 -i]);
        }        
    }
};