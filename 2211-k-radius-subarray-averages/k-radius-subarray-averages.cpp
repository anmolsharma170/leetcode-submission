class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if(2*k+1>nums.size()) return vector<int>(nums.size(),-1);
        if(k==0) return nums;
        vector<int> ans(nums.size(),-1);
        long long tot = 0;
        int n = 2*k+1;
        for(int i=0;i<=2*k;i++){
            tot+=nums[i];
        }
        cout<<tot<<" \n";
        for(int i=k;i<nums.size()-k;i++){
            ans[i]= tot/n;
            tot-=nums[i-k];
            if(i+k+1<nums.size()) tot+=nums[i+k+1];
        }
        return ans;
    }
};