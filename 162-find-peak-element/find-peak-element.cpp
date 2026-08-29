class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int ans=-1;
        int i = 1;
        int j = nums.size()-1;
        int maxidx = 0;
        if(nums.size()==1) return 0;
        if(nums.size()==2){
            if(nums[0]>nums[1]) return 0;
            else return 1;
        }
        while(i<j){
            if(nums[i]>nums[i-1] && nums[i]>nums[i+1]){
                cout<<"i->"<<nums[i]<<" i+1->"<<nums[i+1]<<" i-1->"<<nums[i-1]<<endl;
                return i;
            }
            i++;
        }
        for(int i = 1;i<nums.size();i++){
            if(nums[i]>nums[maxidx]) maxidx = i;
        }
        return maxidx;
    }
};