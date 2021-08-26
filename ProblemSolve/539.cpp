/***************************
 * Minimum Time Difference *
 ***************************/

class Solution {
public:
    //두 시간사이의 차이를 구하는 함수
    int timeDiff(string time1, string time2) {
        //시간 변환
        int hour1 = stoi(time1.substr(0, 2));
        int hour2 = stoi(time2.substr(0, 2));
        
        //분 변환
        int minute1 = stoi(time1.substr(3, 2));        
        int minute2 = stoi(time2.substr(3, 2));
        
        //time1과 time2의 차이를 분으로 나타낸다
        return (hour2 - hour1) * 60 + (minute2 - minute1);
    }
    
    int findMinDifference(vector<string>& timePoints) {
        //시간 순으로 정렬
        sort(timePoints.begin(), timePoints.end());
        
        int len = timePoints.size();
        int minTimeDiff = INT_MAX;
        int tempDiff;
        
        for(int i=0; i<len; i++){
            //현재 시간(timePoints[i])과 이전 시간(timePoints[i-1])간의 시간차를 계산
            //(i - 1 + len) % len을 한 이유는 i가 0일때 가장 큰 시간과의 차이를 구하기 위함
            tempDiff = abs(timeDiff(timePoints[(i - 1 + len) % len], timePoints[i]));
            
            //현재 시간과 이전 시간의 차이와 이전 시간과 현재 시간의 차이를 비교해 더 차이가 없는 쪽 선택
            //ex) 00:00과 23:59는 min(1439, 1)
            tempDiff = min(tempDiff, 1440 - tempDiff);
            //더 작은 차이를 계산
            minTimeDiff = min(minTimeDiff, tempDiff);
            
            if(minTimeDiff == 0){
                break;
            }
        }
        
        return minTimeDiff;
    }
};