class Solution {
public:
    void dfs(vector<vector<int>>& rooms, unordered_set<int> &visited,int curr){
        visited.insert(curr);
        for(auto neigh: rooms[curr]){
            if(!visited.count(neigh)){
                dfs(rooms,visited,neigh);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> visited;
        dfs(rooms,visited,0);
        return rooms.size()==visited.size();
    }
};