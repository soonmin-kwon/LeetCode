/**************
 * Flood Fill *
 **************/

class Solution {
public:
    //최대 범위 저장
    int lenX, lenY;

    void dfs(vector<vector<int>>& image, int y, int x, int targetColor, int newColor) {
        //범위에서 벗어나는 경우 처리
        if(y < 0 || x < 0 || y >= lenY || x >= lenX){
            return;
        }
        
        //이미 바뀌었거나, 바꿀 필요가 없거나, 바꾸면 안 되는 칸인 경우 처리
        if(image[y][x] != targetColor || image[y][x] == newColor){
            return;
        }
        
        //newColor로 색칠
        image[y][x] = newColor;                
        
        //4방향으로 진행
        dfs(image, y + 1, x, targetColor, newColor);
        dfs(image, y - 1, x, targetColor, newColor);
        dfs(image, y, x + 1, targetColor, newColor);
        dfs(image, y, x - 1, targetColor, newColor);
        
        return;
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        lenY = image.size();
        lenX = image[0].size();
        
        dfs(image, sr, sc, image[sr][sc], newColor);
        
        return image;
    }
};