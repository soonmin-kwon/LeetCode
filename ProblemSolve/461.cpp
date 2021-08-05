/********************
 * Hamming Distnace *
 ********************/

class Solution {
public:
    int hammingDistance(int x, int y) {
        //서로 다른 비트만 1로 만듦
        int check = x ^ y;
        int distance = 0;
                    
        //1인 비트 체크
        while(check) {
            if(check & 1){
                distance++;
            }
            check = check >> 1;
        }
    
        return distance;
    }
};