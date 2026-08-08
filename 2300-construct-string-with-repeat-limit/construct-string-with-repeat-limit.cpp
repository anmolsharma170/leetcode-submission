class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char,int> mp;
        for(auto ch: s){
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
            int len = min(repeatLimit,largest.second);
            for(int i=0;i<len;i++){
                res+=largest.first;
            }
            pair<char,int> secondlargest;
            if(largest.second-len>0){
                if(!pq.empty()){
                    secondlargest = pq.top();
                    pq.pop();
                    res+=secondlargest.first;
                }
                else{
                    return res;
                }
                if(secondlargest.second-1>0) pq.push({secondlargest.first,secondlargest.second-1});
                pq.push({largest.first,largest.second-len});
            }
        }
        return res;
    }
};