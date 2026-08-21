class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i = 0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        int total = 0;
        while(k--){
            int x = pq.top();
            pq.pop();
            if(x==0) break;
            x*=-1;
            // total+=x;
            pq.push(x);
        }
        while(!pq.empty()){
            total+=pq.top();
            pq.pop();
        }
        return total;
    }
};