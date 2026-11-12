class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int inc=1,dec=1,finalans=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                inc++;
                if(inc>finalans) finalans = inc;
                if(dec>1) dec = 1;
            } 
            else if(nums[i]<nums[i-1]){
                dec++;
                if(dec>finalans) finalans = dec;
                if(inc>1) inc = 1;
            }
            else{
                inc=1;
                dec=1;
            }
        }
        return finalans;
    }
};