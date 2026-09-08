class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int prevcolor,int newColor){
        int n = image.size();
        int m = image[0].size();
        if(sr<0 || sc<0 || sr>=n || sc>=m) return;
        if(image[sr][sc]!=prevcolor) return;
        image[sr][sc]=newColor;
        dfs(image,sr+1,sc,prevcolor,newColor);
        dfs(image,sr-1,sc,prevcolor,newColor);
        dfs(image,sr,sc+1,prevcolor,newColor);
        dfs(image,sr,sc-1,prevcolor,newColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color) return image;
        int prev = image[sr][sc];
        dfs(image,sr,sc,prev,color);
        return image;
    }
};