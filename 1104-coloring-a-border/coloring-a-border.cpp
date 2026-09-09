class Solution {
public:
    vector<pair<int,int>> internal;
    void dfs(vector<vector<int>>& grid,int row,int col,int color,int initialColor){
        int n = grid.size();
        int m = grid[0].size();
        if(row<0 || col<0 || row>=n || col>=m || grid[row][col]!=initialColor) return;
        grid[row][col]=-color;
        dfs(grid,row+1,col,color,initialColor);
        dfs(grid,row-1,col,color,initialColor);
        dfs(grid,row,col+1,color,initialColor);
        dfs(grid,row,col-1,color,initialColor);
        if(!(row==0 || col==0 || row==n-1 || col==m-1 || grid[row][col-1]!= -color || grid[row][col+1]!= -color ||grid[row-1][col]!= -color ||grid[row+1][col]!= -color)){
            internal.push_back({row,col});
        }
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int initialColor = grid[row][col];
        if(initialColor==color) return grid;
        dfs(grid,row,col,color,initialColor);
        for(auto p:internal){
            int f = p.first;
            int s = p.second;
            cout<<f<<" "<<s<<endl;
            grid[f][s]=initialColor;
        }
        for(int i = 0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]<0){
                    grid[i][j]*=-1;
                }
            }
        }
        return grid;
    }
};