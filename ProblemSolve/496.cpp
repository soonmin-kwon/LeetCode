/**************************
 * Next Greater Element I * 
 **************************/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {        
        vector<int> ans(nums1.size(), -1);
        stack<int> st;
        unordered_map<int,int> hash;
        
        //nums2 배열을 돌면서 nums2의 element들을 스택에 넣는다
        //만약 nums2[i] 값이 스택의 top보다 크면
        //스택에 있는 값의 next greater element는 nums2[i]이다
        for(int num : nums2){            
            while(!st.empty() && st.top() < num){
                hash[st.top()] = num;
                st.pop();
            }
            
            st.push(num);
        }
        
        //hash table을 돌면서 next greater element가 있으면 정답에 추가
        for(int i=0; i<nums1.size(); i++){
            if(hash.find(nums1[i]) != hash.end()){
                ans[i] = hash[nums1[i]];
            }
        }
        
        return ans;
    }
};