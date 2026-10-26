class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int l = 0;
        int r = 0;
        long long currsum = 0;
        int ans = 0;
        int fans = 0;
        while(r<nums.size()){
            int target = nums[r];
            int window = r-l+1;
            currsum+=nums[r];
            long long needed = 1LL*window*target;
            while(needed-currsum>k){
                currsum-=nums[l];
                l++;
                window=r-l+1;
                needed=1LL*window*target;
            }
            ans=r-l+1;
            if(ans>fans) fans=ans;
            r++;
        }
        return fans;
    }
};