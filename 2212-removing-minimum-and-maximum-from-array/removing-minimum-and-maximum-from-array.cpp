class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        cout<<nums.size()<<endl;
        if(nums.size()==1 || nums.size()==2) return nums.size();
        int count1 = 0;
        int count2=0;
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
        cout<<minidx<<"  "<<maxidx<<endl;
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
            cout<<"first"<<endl;
            if(minidx>maxidx) return minidx+1;
            else return maxidx+1;
        }
        if(minidx>nums.size()/2){
            cout<<"second"<<endl;
            minidx = nums.size()-minidx;
        }
        else{
            cout<<"min idx is "<<minidx; 
            cout<<"\nthird"<<endl;
            minidx = minidx+1;
        } 
        if(maxidx>nums.size()/2){
            maxidx = nums.size()-maxidx;
        }
        else maxidx+=1;
        cout<< maxidx <<"->"<< maxele <<" "<<minidx<<"->"<<minele;
        
        return min({minidx+maxidx,onlyfront,onlyback}) ;
    }
};