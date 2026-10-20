class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prepro(n);
        vector<int> suffpro(n);
        vector<int> ans;
        prepro[0] = 1;
        suffpro[n-1]=1;
        int pro = nums[0];
        for(int i = 1;i<n;i++){
            prepro[i]=pro;
            pro*=nums[i];
            cout<<prepro[i]<<" ";
        }
        cout<<endl;
        int prod = nums[n-1];
        for(int i=n-2;i>=0;i--){
            suffpro[i]=prod;
            prod*=nums[i];
            cout<<suffpro[i]<<" ";
        }
        for(int i = 0;i<nums.size();i++){
            prepro[i]*=suffpro[i];
        }
        return prepro;
    }
};