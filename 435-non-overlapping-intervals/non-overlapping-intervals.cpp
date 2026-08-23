bool cmp(vector<int> &a,vector<int> &b){
    return a[1]<b[1];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int count = 0;
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),cmp);
        int lastEnd = intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<lastEnd){
                count++;
                lastEnd = min(lastEnd,intervals[i][1]);
            }
            else{
                lastEnd = intervals[i][1];
            }
        }
        return count;
    }
};