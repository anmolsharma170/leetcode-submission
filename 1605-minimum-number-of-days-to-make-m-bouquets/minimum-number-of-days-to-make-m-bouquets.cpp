class Solution {
public:
    bool possible(vector<int> &arr,int day,int m,int k){
        int count = 0;
        int noOfB = 0;
        for(int i = 0;i<arr.size();i++){
            if(arr[i]<=day) count++;
            else{
                noOfB+= count/k;
                count = 0;
            }
        }
        noOfB+= count/k;
        if(noOfB>=m) return true;
        else return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(m*1LL*k *1LL > bloomDay.size()) return -1;
        int minele = INT_MAX;
        int maxele = INT_MIN;
        for(int i = 0;i<bloomDay.size();i++){
            minele = min(minele,bloomDay[i]);
            maxele = max(maxele,bloomDay[i]);
        }
        int low = minele;
        int high = maxele;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(bloomDay,mid,m,k)){
                high=mid-1;
            }
            else low = mid+1;
        }
        return low;
    }
};