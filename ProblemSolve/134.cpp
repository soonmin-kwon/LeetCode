/***************
 * Gas Station *
 ***************/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0, gasSum = 0, startIdx = 0, len = gas.size();
        
        for(int i=0; i<len; ++i){
            sum += gas[i] - cost[i];
            gasSum += gas[i] - cost[i];
            
            if(gasSum < 0){
                gasSum = 0;
                startIdx = i + 1;
            }
        }
        
        return (sum < 0 ? -1 : startIdx);
    }
};