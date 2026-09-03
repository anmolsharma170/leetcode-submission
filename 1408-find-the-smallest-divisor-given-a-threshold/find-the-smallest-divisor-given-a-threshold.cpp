class Solution {
public:
    long long cal(vector<int> nums,int mid){
        long long total = 0;
        for(int i=0;i<nums.size();i++){
            total+= ((long long)nums[i]+mid-1)/mid;
        }
        return total;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int res = 0;
        int low = 1;
        int  high = *max_element(nums.begin(),nums.end());
        while(low<=high){
            int mid = low+(high-low)/2;
            int ans=-1;
            long long sum = cal(nums,mid);
            if(sum<=threshold){
                ans=sum;
                high=mid-1;
            }
            else low=mid+1;
        }
        return low;
    }
};