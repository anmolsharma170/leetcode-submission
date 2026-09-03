class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int smallestOdd = INT_MAX;
        int oddCount = 0;
        for(int i = 0;i<nums1.size();i++){
            if(nums1[i]%2!=0){
                oddCount++;
                smallestOdd = min(smallestOdd,nums1[i]);
            }
        }
        bool ans = true;
        if(oddCount==0) return true;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2!=0) continue;
            if(nums1[i]>smallestOdd) continue;
            return false;
        }
        return true;
    }
};