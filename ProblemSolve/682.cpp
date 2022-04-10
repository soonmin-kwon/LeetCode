/*****************
 * Baseball Game *
 *****************/

class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        int ans = 0;
        
        for(int i=0; i<ops.size(); ++i){
            if(ops[i] == "+"){
                int prev1 = st.top();
                st.pop();
                int prev2 = st.top();
                st.push(prev1);
                st.push(prev2 + prev1);
            }
            else if(ops[i] == "D"){
                int prev = st.top();
                st.push(prev * 2);
            }
            else if(ops[i] == "C"){
                st.pop();
            }
            else{
                st.push(stoi(ops[i]));
            }
        }
        
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        
        return ans;
    }
};