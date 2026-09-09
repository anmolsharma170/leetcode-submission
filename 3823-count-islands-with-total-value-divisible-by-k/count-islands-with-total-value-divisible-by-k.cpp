class Solution {
public:
    void dfs(vector<vector<int>>& grid,int row,int col,long long &total){
        if(row<0 || col<0 || row>=grid.size() || col>=grid[0].size() || grid[row][col]==0) return;
        total+=grid[row][col];
        grid[row][col]=0;
        dfs(grid,row+1,col,total);
        dfs(grid,row-1,col,total);
        dfs(grid,row,col+1,total);
        dfs(grid,row,col-1,total);
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]==0) continue;
                long long total = 0;
                dfs(grid,i,j,total);
                if(total%k==0) count++;
            }
        }
        return count;
    }
};