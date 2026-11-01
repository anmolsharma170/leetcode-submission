class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int i=0,j=1,count=0;
        unordered_map<int,int> mp;
        sort(nums.begin(),nums.end());
        while(j<nums.size()){
            if(i==j){
                j++;
                continue;
            }
            long long ans = nums[j]-nums[i];
            cout<<nums[i]<<" "<<nums[j]<<"  "<<ans<<endl;

            if(ans==k){
                count++;
                int x = nums[i];
                int y = nums[j];
                while(i<nums.size() && nums[i]==x) i++;
                while(j<nums.size() && nums[j]==y) j++;
            }
            else if(ans<k){
                j++;
            }
            else{
                i++;
            }
        }
        return count;
    }
};