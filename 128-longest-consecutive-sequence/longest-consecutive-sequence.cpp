class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return n;
        unordered_map<int,bool> mp;
        unordered_set<int> st;
        for(int i = 0;i<n;i++){
            int ele = nums[i];
            if(mp.find(ele)==mp.end()){
                st.insert(ele);
                bool smaller = mp.find(ele-1)!=mp.end();
                bool bigger = mp.find(ele+1)!=mp.end();
                if(smaller && bigger){
                    mp[ele] = false;
                    mp[ele+1]= false;
                }
                else if(smaller){
                    mp[ele]=false;
                }
                else if(bigger){
                    mp[ele]=true;
                    mp[ele+1]=false;
                }
                else mp[ele]=true;
            }
        }
        int consecCount = 0;
        int maxStart = INT_MIN;
        for(auto p: mp){
            if(p.second){
                int count = 0;
                int ele = p.first;
                while(st.find(ele+1)!=st.end()){
                    count++;
                    ele++;
                }
                if(count>consecCount){
                    consecCount = count;
                    maxStart = ele;
                }
            }
        }

        return consecCount+1;
    }
};