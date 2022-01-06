/***************
 * Car Pooling *
 ***************/

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        if(trips[0][0] > capacity){
            return false;
        }
        
        //빨리 내리는 순으로 정렬
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> destination;
        
        //순서대로 태우기 위해 정렬
        sort(trips.begin(), trips.end(), 
             [](vector<int> &a, vector<int> &b){
                return a[1] < b[1];
        });
        
        destination.push(make_pair(trips[0][2],trips[0][0]));
        capacity -= trips[0][0];
        
        for(int i=1; i<trips.size(); i++){
            //태울 때만 확인해서 내려야 되는 경우 전부 내려주기
            while(!destination.empty() && destination.top().first <= trips[i][1]){
                capacity += destination.top().second;
                destination.pop();
            }
            
            capacity -= trips[i][0];
            
            if(capacity < 0){
                return false;
            }            
            else{
                destination.push(make_pair(trips[i][2], trips[i][0]));
            }
        }
        
        return true;
    }
};