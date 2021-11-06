/*********************
 * Single Number III *
 *********************/

public class Solution {
    public int[] SingleNumber(int[] nums) {
        int mask = 0;
        
        if(nums.Length == 2){
            return nums;
        }
        
        //한 수를 두번 xor하게 되면 0이 된다
        //결국 unique한 두 수만 생존
        foreach(int num in nums){
            mask ^= num;
        }
        
        /*마지막 bit 뽑기*/
        //서로 다른 수 a와 b를 xor하면
        //반드시 1이 되는 bit가 존재
        //그 위치의 bit와 nums[i]을 & 연산하면 a와 b를 분리할 수 있다                
        mask &= -mask;
        
        int[] ans = new int[2];
        
        /*마지막 비트와 &연산 진행*/
        //그 자리수에는 a ^ b의 결과가 찍혀있는 거고 1이 되려면 a = 1, b = 0이거나 a = 0, b = 1이 된다
        //다른 수들은 결국 두번씩 나오기 때문에 무슨 수가 나오든 사라진다
        //고로 &연산의 결과가 0인 값들을 전부 xor하고 그렇지 않은 값들을 전부 xor하면 두 수 a와 b가 분리된다
        foreach(int num in nums){
            if((num & mask) == 0){
                ans[1] ^= num;
            }
            else{
                ans[0] ^= num;
            }
        }
        
        return ans;
    }
}