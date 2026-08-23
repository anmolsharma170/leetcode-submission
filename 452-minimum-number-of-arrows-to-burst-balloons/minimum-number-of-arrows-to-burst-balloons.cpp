bool cmp(vector<int> &a,vector<int> &b){
    return a[1]<b[1];
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(),points.end(),cmp);
        int count = 0;
        int  lastEnd = points[0][1];
        for(int i=1;i<points.size();i++){
            if(points[i][0]<=lastEnd){
                count++;
                lastEnd = min(lastEnd,points[i][1]);
            } 
            else lastEnd = points[i][1];
        }
        return points.size()-count;
    }
};