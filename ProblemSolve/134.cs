/***************
 * Gas Station *
 ***************/

public class Solution {
    public int CanCompleteCircuit(int[] gas, int[] cost) {
        int gasSum = 0;
        int startIdx = 0;
        int len = gas.Length;
        int sum = 0;
        
        //sum이 - 값인 경우 답이 없는 경우
        //답이 없는 경우를 제외하면 무조건 하나의 답만 존재
        //시작점에서 계산을 시작했을 때 gasSum이 - 값이 나오면 답이 아닌 경우
        //한 사이클을 돌았을 때 gasSum 값이 -값이 아니면 그 gasSum을 계산하기 시작한 idx가 정답
        for(int i=0; i<len; ++i){
            sum += gas[i] - cost[i];
            gasSum += gas[i] - cost[i];
            
            if(gasSum < 0){
                startIdx = i+1;
                gasSum = 0;
            }
        }
        
        return (sum < 0 ? -1 : startIdx);
    }
}