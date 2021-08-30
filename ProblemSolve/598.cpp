/*********************
 * Range Addition II *
 *********************/

//참고 : https://leetcode.com/problems/range-addition-ii/discuss/1434611/C%2B%2B-easy-solution-oror-O(n)-oror-With-comments

class Solution {
public:
    //0, 0부터 ops[i][0], ops[i][1]까지의 범위를 1씩 늘려나간다
    //가장 큰 element의 개수를 세면 되기 때문에
    //ops에 들어있는 row, col중에 가장 작은 row, col을 골라내면
    //row * col 만큼이 가장 큰 element의 개수가 된다
    
    /*
    ex)
    m = 3, n = 3
    ops = {{1, 1}, {1, 2}, {2, 2}, {3, 3}};
    
    1 0 0       2 1 0       3 2 0       4 3 1
    0 0 0   ->  0 0 0   ->  1 1 0   ->  2 2 1
    0 0 0       0 0 0       0 0 0       1 1 1
    
    return 1 * 1
    
    */
    int maxCount(int m, int n, vector<vector<int>>& ops) {        
        int row = m;
        int col = n;
        
        int len = ops.size();
        
        for(int i=0; i<len; i++){
            row = min(row, ops[i][0]);
            col = min(col, ops[i][1]);
        }
        
        return row * col;
    }
};