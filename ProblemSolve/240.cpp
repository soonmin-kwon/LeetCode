/*************************
 * Search a 2D Matrix II *
 *************************/

class Solution {
public:
    //참고 : https://leetcode.com/problems/search-a-2d-matrix-ii/discuss/1079514/C%2B%2B-or-Binary-Search-(2-variations)-or-O(m%2Bn)-or-Explanation-(with-example)-%2B-Diagram
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int len = matrix.size();
        int len2 = matrix[0].size();
        
        if(len == 0 && len2 == 0){
            return false;
        }
        
        int row = 0;
        int col = len2 -1;
        
        while(row < len && col >= 0){
            if(matrix[row][col] == target){
                return true;
            }
            else if(matrix[row][col] > target){
                col--;
            }
            else{
                row++;
            }
        }
        
        return false;
    }
    
    //O(M log N)
    bool searchMatrix2(vector<vector<int>>& matrix, int target) {
        int left;
        int right;
        int mid;
        int len = matrix.size();
        int len2 = matrix[0].size() - 1;
        
        //target이 범위 안에 있으면 그 row를 binary search
        for(int i=0; i<len; i++){            
            if(target == matrix[i][0] || target == matrix[i][len2]){
                return true;
            }
            else if(target > matrix[i][0] && target <matrix[i][len2]){
                left = 0;
                right = len2;
                
                while(left <= right){
                    mid = (left + right)/2;
                    
                    if(matrix[i][mid] == target){
                        return true;
                    }
                    else if(matrix[i][mid] > target){
                        right = mid -1;
                    }
                    else{
                        left = mid + 1;
                    }
                }
            }
        }
        
        return false;
    }
};