class Solution {
public:
    vector<vector<int>> internals;
    void dfs(vector<vector<int>> &grid,int row,int col,int prevcolor,int newcolor){
        if(row<0 || col<0 || row>=grid.size() || col>=grid[0].size()) return;
        if(grid[row][col]!=prevcolor) return;
        grid[row][col]= -newcolor;
        dfs(grid,row+1,col,prevcolor,newcolor);
        dfs(grid,row-1,col,prevcolor,newcolor);
        dfs(grid,row,col+1,prevcolor,newcolor);
        dfs(grid,row,col-1,prevcolor,newcolor);
        if(!(row==0 || col==0 || row==grid.size()-1 || col==grid[0].size()-1 || grid[row-1][col]!= -newcolor || grid[row+1][col]!= -newcolor|| grid[row][col-1]!= -newcolor|| grid[row][col+1]!= -newcolor)){
            internals.push_back({row,col});
        }
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int prevcolor = grid[row][col];
        // if(prevcolor==color) return grid;
        dfs(grid,row,col,prevcolor,color);
        for(auto p:internals){
            int row = p[0];
            int col = p[1];
            grid[row][col]=prevcolor;
        }
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j]<0) grid[i][j]*=-1;
            }
        }
        return grid;
    }
};