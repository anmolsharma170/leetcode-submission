class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int fcount = 0;
        int count = 0;
        int n = nums.size();
        if(n%2!=0){
            // cout<<"entered\n";
            int median = nums[n/2];
            // cout<<"median "<<median<<"\n";
            for(int i=0;i<n;i++){
                if(i!=n/2){
                    // cout<<"entry nested "<<nums[i]<<"\n";
                    int needed=abs(median-nums[i]);
                    // cout<<"needed "<<needed<<"\n";
                    fcount+=needed;
                    // cout<<"count "<<count<<"\n";
                }
            }

        }
        else{
            cout<<"entered else\n";
            int med1=nums[n/2];
            int med2=nums[n/2-1];
            int count1 = 0;
            int count2=0;
            for(int i=0;i<n;i++){
                if(i!=n/2){
                    int needed = abs(med1-nums[i]);
                    count1+=needed;
                }
                if(i!=n/2-1){
                    int needed = abs(med2-nums[i]);
                    count2+=needed;
                }
            }
            // for(int i=0;i<n;i++){
                
            // }
            fcount=(count1<count2)?count1:count2;
        }
        return fcount;
    }
};