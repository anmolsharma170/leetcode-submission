class Solution {
public:
    bool ispresent(vector<int> &nums,int n){
        for(int i=0;i<nums.size();i++){
            if(n==nums[i]) return true;
        }
        return false;
    }
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ans;
        for(int i=nums[0];i<nums[nums.size()-1];i++){
            if(!ispresent(nums, i)) ans.push_back(i);
        }
        return ans;
    }
};