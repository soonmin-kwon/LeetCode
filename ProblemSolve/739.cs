/**********************
 * Daily Temperatures *
 **********************/

public class Solution {
    public int[] DailyTemperatures(int[] temperatures) {
        int len = temperatures.Length;
        int warmest = temperatures[len-1];
        int[] ans = new int[len];
        
        //거꾸로 순회하기 때문에 현재 날을 기준으로 가장 따뜻한 날의 온도를 기록할 수 있다.
        //현재가 가장 따뜻한 날이면 온도만 갱신하면 되고
        //가장 따뜻한 날이 아니면 가장 따뜻한 날이 몇번째 날인지 찾으면 된다
        //ans에는 가장 따뜻한 날과의 차이를 기록하므로 ans를 참조하면서 정답을 찾으면 된다.
        //예를 들어 temperatures = [73,74,75,71,69,72,76,73]인 경우
        //i=2일때, ans = [0,0,0,2,1,1,0,0]이고, temperatures[2] = 75, warmest = 76이다.
        //temperatures[3] <= temperatures[2]이고 ans[3] = 2이다.
        //ans[3] = 2라는 뜻은 ans[4]를 확인하지 않아도 temperatures[2]보다 작다는 뜻이다.
        //ans의 값만큼 건너 뛰면서 조건에 맞는지 확인해 정답을 구한다
        for(int i=len-2; i>=0; i--){
            int todayTemp = temperatures[i];
            //온도 갱신
            if(todayTemp >= warmest){
                warmest = todayTemp;
                continue;
            }
            
            int wamerDay = 1;
            while(temperatures[i + wamerDay] <= todayTemp){
                wamerDay += ans[i + wamerDay];
            }
            
            ans[i] = wamerDay;
        }
        
        return ans;
    }
}