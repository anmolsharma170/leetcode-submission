class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        if(k<0) return 0;
        int count = 0;
        for(auto ele:nums){
            mp[ele]++;
        }
        for(auto p: mp){
            int keyval = p.first;
            if(k==0){
                if(p.second>1) count++;
            }
            else{
                int rem = keyval+k;
                if(mp.find(rem)!=mp.end()) count++;
            }
            
        }
        return count;
    }
};