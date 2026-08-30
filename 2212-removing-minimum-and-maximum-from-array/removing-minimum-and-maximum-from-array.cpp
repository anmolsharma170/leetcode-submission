class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        cout<<nums.size()<<endl;
        if(nums.size()==1 || nums.size()==2) return nums.size();
        int minele=INT_MAX,maxele =INT_MIN,minidx=-1,maxidx=-1;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]<minele){
                minele = nums[i];
                minidx = i;
            }
            if(nums[i]>maxele){
                maxele = nums[i];
                maxidx = i;
            }
        }
        int onlyfront = 0;
        if(minidx>maxidx){
            onlyfront = minidx+1;
        }
        else onlyfront = maxidx+1;
        int onlyback = 0;
        if(minidx<maxidx){
            onlyback = nums.size()-minidx;
        }
        else onlyback= nums.size()-maxidx;
        if(minidx<nums.size()/2 && maxidx<nums.size()/2){
            if(minidx>maxidx) return minidx+1;
            else return maxidx+1;
        }
        if(minidx>nums.size()/2){
            minidx = nums.size()-minidx;
        }
        else{
            minidx = minidx+1;
        } 
        if(maxidx>nums.size()/2){
            maxidx = nums.size()-maxidx;
        }
        else maxidx+=1;
        return min({minidx+maxidx,onlyfront,onlyback}) ;
    }
};