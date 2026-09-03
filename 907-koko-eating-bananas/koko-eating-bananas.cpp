class Solution {
public:
    long long cal(vector<int> piles,int x){
        long long timetaken = 0;
        for(int i = 0;i<piles.size();i++){
            timetaken+=((long long)piles[i]+x-1)/x;
        }
        return timetaken;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());
        int ans = -1;
        while(low<=high){
            int  mid = low+(high-low)/2;
            long long timetaken = cal(piles,mid);
            if(timetaken<=h){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};