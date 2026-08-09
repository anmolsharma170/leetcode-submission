class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> mp;
        int ans = 0;
        mp[answers[0]+1]++;
        ans+=answers[0]+1;
        for(int i=1;i<answers.size();i++){
            if(mp.find(answers[i]+1)!=mp.end() && mp[answers[i] + 1] < answers[i] + 1){
                mp[answers[i]+1]++;
                if(mp[answers[i]+1]>=answers[i]+1){
                    mp.erase(answers[i]+1);
                }
                
            }
            else{
                mp[answers[i]+1]++;
                ans+=answers[i]+1;
            }
        }
        return ans;
    }
};