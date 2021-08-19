/****************
 * Maximum Swap *
 ****************/

class Solution {
public:
    int maximumSwap(int num) {
        string temp = to_string(num);
        int len = temp.size();
        
        //각 temp의 idx에 대해서 몇번째 idx와 스왑하면 최대값인지 저장
        //ex) 2736 -> maximum = {{7,2},{7,2},{6,3},{6,3}}
        //맨 끝자리부터 갱신해나간다
        vector<pair<int,int>> maximum(len);
        
        maximum[len-1] = make_pair(temp[len-1] -'0', len-1);
        
        //끝자리부터 갱신
        /* ex) 2736
         * 6 -> 6           maximum = {{},{},{},{6,3}}
         * 36 -> 63         maximum = {{},{},{6,3},{6,3}}
         * 736 -> 763       maximum = {{},{7,2},{6,3},{6,3}}
         * 2736 -> 7236     maximum = {{7,2},{7,2},{6,3},{6,3}}
         */
        for(int i= len-2; i>=0; i--){
            //현재 값이 이전 값보다 클 경우 현재 값으로 바꿔나가야 한다
            if(temp[i] -'0' > maximum[i+1].first){
                maximum[i] = make_pair(temp[i]-'0', i);
            }
            else{
                maximum[i] = maximum[i+1];
            }
        }
        
        //제일 앞자리부터 순회해야 가장 큰 자리수를 swap할 수 있다
        for(int i=0; i<len; i++){
            if(maximum[i].first > temp[i] - '0'){
                swap(temp[i], temp[maximum[i].second]);
                return stoi(temp);
            }
        }
        
        return num;
    }
};