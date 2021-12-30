/***********************************
 * Smallest Integer Divisible by K *
 ***********************************/

public class Solution {
    public int SmallestRepunitDivByK(int k) {
        int remain = 0;
        
        if(k % 2 == 0 || k % 5 == 0){
            return -1;
        }
        
        //k번만 for문을 도는 이유
        //나머지가 나올 수 있는 범위 = 0~k-1
        //나머지가 겹치는 경우 2, 5 밖에 없음. 따라서 k번만 돌아도 나눌 수 있는 수인지 확인할 수 있음
        for(int ans=1; ans<=k; ++ans){
            //미리 나머지를 계산하나 한번에 계산하나 같은 값이 나온다
            //미리 계산하면서 찾는다
            remain = (remain * 10 + 1) % k;
            
            if(remain == 0){
                return ans;
            }
        }
        
        return -1;
    }
}