class Solution {
public:
    bool canShip(vector<int>& weights, int days,int capacity){
        int day = 1,curr = 0;
        for(int w: weights){
            if(w+curr>capacity){
                day++;
                curr=w;
            }
            else{
                curr+=w;
            }
        }
        if(day>days) return false;
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int lo = INT_MIN, high = 0;
        for(int i = 0;i<weights.size();i++){
            lo = max(lo,weights[i]);
            high+=weights[i];
        }
        int ans = -1;
        while(lo<=high){
            int mid = lo+(high-lo)/2;
            if(canShip(weights,days,mid)){
                ans = mid;
                high = mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        return ans;
    }
};