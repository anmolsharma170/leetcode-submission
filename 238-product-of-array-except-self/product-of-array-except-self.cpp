class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix_pro(n,1);
        vector<int> suffix_pro(n,1);
        vector<int> ans(n);
        prefix_pro[0]=1;
        suffix_pro[n-1]=1;
        for(int i=1;i<n;i++){
            prefix_pro[i]=prefix_pro[i-1]*nums[i-1];
        }
        for(int i = n-2;i>=0;i--){
            suffix_pro[i]=suffix_pro[i+1]*nums[i+1];
        }
        for(int i=0;i<ans.size();i++){
            ans[i]=suffix_pro[i]*prefix_pro[i];
        }
        return ans;
    } 
};