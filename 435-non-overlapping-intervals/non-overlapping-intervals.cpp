bool cmp(vector<int> &a,vector<int> &b){
    return a[1]<b[1];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),cmp);
        int lastIntervalEnd = intervals[0][1];
        int count = 0;
        for(int i=1;i<n;i++){
            if(intervals[i][0] < lastIntervalEnd){
                count++;
            }
            else{
                lastIntervalEnd = intervals[i][1];
            }
        }
        return count;
    }
};