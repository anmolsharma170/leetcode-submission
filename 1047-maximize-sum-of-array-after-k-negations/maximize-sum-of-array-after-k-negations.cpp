class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        int sum = 0;
        for(int i = 0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        while(k--){
            int n = pq.top();
            pq.pop();
            n = -1*n;
            pq.push(n);
        }
        while(!pq.empty()){
            int n = pq.top();
            pq.pop();
            sum+=n;
        }
        return sum;
    }
};