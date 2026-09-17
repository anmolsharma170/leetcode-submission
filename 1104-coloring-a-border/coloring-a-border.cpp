class Solution {
public:
    vector<vector<int>> internals;
    void dfs(vector<vector<int>>& grid, int row, int col, int newcolor,int oldcolor){
        if(row<0 || col<0 || row>=grid.size() || col>=grid[0].size()) return;
        if(grid[row][col]!=oldcolor) return;
        grid[row][col]= -newcolor;
        dfs(grid,row+1,col,newcolor,oldcolor);
        dfs(grid,row-1,col,newcolor,oldcolor);
        dfs(grid,row,col+1,newcolor,oldcolor);
        dfs(grid,row,col-1,newcolor,oldcolor);
        if(!(row==0 || col==0 || row==grid.size()-1 || col==grid[0].size()-1 || grid[row-1][col]!= -newcolor || grid[row+1][col]!= -newcolor || grid[row][col-1]!= -newcolor || grid[row][col+1]!= -newcolor)){
            internals.push_back({row,col});
        }
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int originalColor = grid[row][col];
        if(originalColor==color) return grid;
        dfs(grid,row,col,color,originalColor);
        for(auto p:internals){
            int row = p[0];
            int col = p[1];
            cout<<row<<" "<<col<<endl;
            grid[row][col]=originalColor;
        }
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j]<0) grid[i][j]*=-1;
            }
        }
        return grid;
    }
};