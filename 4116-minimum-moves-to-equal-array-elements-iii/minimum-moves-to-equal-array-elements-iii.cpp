class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int target = nums[n-1];
        int count = 0;
        for(int i=0;i<nums.size()-1;i++){
            count+=target-nums[i];
        }
        return count;
    }
};