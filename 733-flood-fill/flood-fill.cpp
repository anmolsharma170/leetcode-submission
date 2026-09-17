class Solution {
public:
    void helper(vector<vector<int>>& image, int sr, int sc, int oldcolor,int newcolor){
        if(sr<0 || sc<0 || sr>=image.size() || sc>=image[0].size()) return;
        if(image[sr][sc]!=oldcolor) return;
        image[sr][sc]=newcolor;
        helper(image,sr+1,sc,oldcolor,newcolor);
        helper(image,sr-1,sc,oldcolor,newcolor);
        helper(image,sr,sc+1,oldcolor,newcolor);
        helper(image,sr,sc-1,oldcolor,newcolor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color) return image;
        int oldcolor = image[sr][sc];
        helper(image,sr,sc,oldcolor,color);
        return image;
    }
};