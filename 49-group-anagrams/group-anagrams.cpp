class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        vector<vector<string>> ans;
        for(int i = 0;i<strs.size();i++){
            string str = strs[i];
            string s = str;
            sort(s.begin(),s.end());
            mp[s].push_back(str);
        }
        for(auto p: mp){
            vector<string> v = p.second;
            for(auto ele: v){
                cout<<ele<<" ";
            }
            ans.push_back(v);
            cout<<endl;
        }
        return ans;
    }
};