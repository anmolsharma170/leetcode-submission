class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int len = nums.size();
        int sum = 0;
        for(int i = 0;i<len;i++){
            if(len%(i+1)==0){
                int x = nums[i]*nums[i];
                sum+=x;
            }
        }
        return sum;
    }
};