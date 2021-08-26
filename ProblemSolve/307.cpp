/*****************************
 * Range Sum Query - Mutalbe *
 *****************************/

/*참고 : https://m.blog.naver.com/ndb796/221282210534
       : https://leetcode.com/problems/range-sum-query-mutable/discuss/1281195/Clean-Solution-w-Explanation-or-Segment-Tree-or-Beats-100
       : https://leetcode.com/problems/range-sum-query-mutable/solution/
*/

class NumArray {
public:
    inline static int len;
    int* segTree;
    
    NumArray(vector<int>& nums) {
        len = nums.size();
        
        //모든 값 커버
        segTree = (int*)malloc(4 * len * sizeof(int));
        buildTree(nums, 1, 0, len - 1);
    }
    
    void buildTree(vector<int>& nums, int node, int start, int end) {
        if(start == end){
            segTree[node] = nums[start];
        }
        else{
            int mid = (start + end) / 2;
            buildTree(nums, 2* node, start, mid);
            buildTree(nums, 2* node + 1, mid + 1, end);
            
            segTree[node] = segTree[node*2] + segTree[node*2 + 1];
        }                
    }
    
    void update(int index, int val, int node = 1, int start = 0, int end = len - 1) {
        if(start == end){
            segTree[node] = val;
        }
        else{
            int mid = (start + end) / 2;
            if(index <= mid){
                update(index, val, 2*node, start, mid);
            }
            else{
                update(index, val, 2*node + 1, mid+1, end);
            }
            
            segTree[node] = segTree[node*2] + segTree[node*2 + 1];
        }                
    }
    
    int sumRange(int left, int right, int node = 1, int start = 0, int end = len - 1) {
        if(left > right){
            return 0;
        }
        
        if(start == left && end == right){
            return segTree[node];
        }
        
        int mid = (start + end) / 2;
        
        return sumRange(left, min(right, mid), 2*node, start, mid) + sumRange(max(left, mid + 1), right, 2*node + 1, mid + 1, end);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */