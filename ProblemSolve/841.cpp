/******************
 * Keys and Rooms *
 ******************/

class Solution {
public:
    //가능한 모든 방을 탐색, Depth-First Search
    void dfs(vector<vector<int>>& rooms, vector<bool>& visitied, int room){
        //중복 탐색 방지
        visitied[room] = true;
        
        for(auto x : rooms[room]){
            if(!visitied[x]){
                dfs(rooms, visitied, x);
            }
        }
        
        return;
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visitied(rooms.size());
        
        dfs(rooms, visitied, 0);
        
        //도달 못한 방이 있으면 false
        for(auto check : visitied){
            if(!check){
                return check;
            }
        }
        
        return true;
    }
};