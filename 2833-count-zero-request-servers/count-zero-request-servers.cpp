class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        vector<int> ans(queries.size());
        sort(logs.begin(),logs.end(),[](auto &a,auto &b){
            return a[1]<b[1];
        });
        vector<pair<int,int>> vec;
        for(int i=0;i<queries.size();i++){
            vec.push_back({queries[i],i});
        }
        sort(vec.begin(),vec.end());
        unordered_map<int,int> mp;
        int left = 0, right = 0;
        for(int k = 0;k<vec.size();k++){
            int end = vec[k].first;
            int start = end-x;
            int idx = vec[k].second;
            while( right<logs.size() && logs[right][1]<=end){
                mp[logs[right][0]]++;
                right++;
            }
            // int left=0, right=0;
            while(left<logs.size() && logs[left][1]<start){
                mp[logs[left][0]]--;
                if(mp[logs[left][0]]==0) mp.erase(logs[left][0]);
                left++;
            }
            int count =n- mp.size();
            ans[idx]=count;
        }

        return ans;
    }
};