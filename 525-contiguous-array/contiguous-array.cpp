class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // unordered_map<prefixsum,firstocc>;
        int n = nums.size();
        long long int ans = 0;
        unordered_map<int,int> mp;
        vector<long long int> prefixsum(n+1);
        prefixsum[0]=0;
        mp[0]=0;
        
        cout<<endl;
        for(int i = 1;i<=n;i++){
            int val = (nums[i-1]==0)?-1:1;
            prefixsum[i]=prefixsum[i-1]+val;
            if(mp.find(prefixsum[i])==mp.end()){
                mp[prefixsum[i]]=i;
            }
            else{
                int firocc = mp[prefixsum[i]];
                if(i-firocc>ans) ans=i-firocc;
            }
        }
        return ans;

    }
};