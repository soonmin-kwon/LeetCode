/***********************************************************
 * Average Salary Excluding the Minimum and Maximum Salary *
 ***********************************************************/

class Solution {
public:
    double average(vector<int>& salary) {
        double ans = 0.0;
        int minimum = INT_MAX, maximum = INT_MIN;
        
        //한번 salary 배열을 돌면서 최소, 최대 값을 찾으면서 모든 salary를 더해준다
        for(int s : salary){
            minimum = min(minimum, s);
            maximum = max(maximum, s);
            
            ans += s;
        }
        
        //모든 salary의 값에서 minimum, maximum값을 빼서 평균을 구한다
        ans = ans - minimum - maximum;
        
        //모든 salary는 unique하기 때문에 salary.size() - 2로 나눠서 평균을 구한다
        return ans / (salary.size() - 2);
    }
};