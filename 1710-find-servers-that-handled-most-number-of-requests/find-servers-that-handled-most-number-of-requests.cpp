class Solution {
public:
    typedef pair<int,int> pp;
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> available_servers;
        for(int i=0;i<k;i++){
            available_servers.insert(i);
        }
        priority_queue<pp,vector<pp>,greater<pp>> busy_servers;
        vector<int> CountServerRequest(k,0);
        for(int i=0;i<arrival.size();i++){
            int time = arrival[i];

            while(!busy_servers.empty() && busy_servers.top().first<=time){
                int server = busy_servers.top().second;
                busy_servers.pop();
                available_servers.insert(server);
            }
            int target = i%k;
            auto it = available_servers.lower_bound(target);
            if(it==available_servers.end()){
                it=available_servers.begin();
            }
            if(available_servers.empty()){
                continue;
            }

            int targetServer = *it;
            available_servers.erase(it);
            busy_servers.push({load[i]+time,targetServer});
            CountServerRequest[targetServer]++;
            // if(available_servers.find(target)!=available_servers.end()){

            // }
        }
        int maxreq = *max_element(CountServerRequest.begin(),CountServerRequest.end());
        vector<int> ans;
        for(int i=0;i<CountServerRequest.size();i++){
            if(CountServerRequest[i]==maxreq){
                ans.push_back(i);
            }
        }
        return ans;
    }
};