class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char,int> mp;
        for(char ch: s){
            mp[ch]++;
        }
        priority_queue<pair<char,int>> pq;
        for(auto p: mp){
            pq.push(p);
        }
        string res = "";
        while(!pq.empty()){
            auto largest = pq.top();
            pq.pop();
            int len = min(largest.second,repeatLimit);
            for(int i=0;i<len;i++){
                res+=largest.first;
            }
            pair<char,int> seclargest;
            if(largest.second-len>0){
                if(!pq.empty()){
                    seclargest = pq.top();
                    pq.pop();
                    res+=seclargest.first;
                }
                else return res;
                if(seclargest.second-1>0){
                    pq.push({seclargest.first,seclargest.second-1});
                }
                pq.push({largest.first,largest.second-len});
            }
        }
        return res;
    }
};