class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
       
        unordered_map<char,int> mp;
        int ans = 0;
        int tempans = 0;
        for(int j=0;j<s.length();j++){
            char a = s[j];
            if(mp.find(a)!=mp.end() && mp[a]>=i){
                tempans=j-i;
                if(tempans>ans) ans = tempans;
                i=mp[a]+1;
            }
            mp[a]=j;
            tempans=j-i+1;
            if(tempans>ans) ans = tempans;
        }
        return ans;
    }
};