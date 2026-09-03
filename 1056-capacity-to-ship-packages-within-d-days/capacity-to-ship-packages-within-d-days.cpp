class Solution {
public:
    bool canship(vector<int> &weights,int days,int capacity){
        int day=1,curr=0;
        for(int w:weights){
            if(curr+w>capacity){
                day++;
                curr=w;
            }
            else{
                curr+=w;
            }
        }
        if(day<=days) return true;
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int lo=INT_MIN,hi=0;
        for(int i=0;i<weights.size();i++){
            lo=max(lo,weights[i]);
            hi+=weights[i];
        }
            int ans = -1;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(canship(weights,days,mid)){
                ans = mid;
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return ans;
    }
};