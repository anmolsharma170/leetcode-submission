#define pp pair<int,int> 
class Solution {
public:
    int getdigsum(int n){
        int ans = 0;
        while(n>0){
            int lst = n%10;
            ans+=lst;
            n/=10;
        }
        return ans;
    }
    int minSwaps(vector<int>& nums) {
        int ans = 0;
        priority_queue<pp,vector<pp>,greater<pp>> pq;
        map<int,int> mp;
        for(int i = 0;i<nums.size();i++){
            int num = nums[i];
            int digsum = getdigsum(num);
            pq.push({digsum,num});
            mp[num]=i;
        }
        vector<int> sorted;
        while(!pq.empty()){
            sorted.push_back(pq.top().second);
            pq.pop();
        }
        vector<bool> visited(nums.size(),false);
        for(int i = 0;i<nums.size();i++){
            if(visited[i] || mp[sorted[i]]==i){
                continue;
            }
            int j=i,cycle = 0;
            while(!visited[j]){
                visited[j]=true;
                j=mp[sorted[j]];
                cycle++;
            }
            ans+=cycle-1;
        }

        return ans;
    }
};