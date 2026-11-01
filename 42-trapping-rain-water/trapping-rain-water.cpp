class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftmax(n);
        vector<int> rightmax(n);
        leftmax[0]= height[0];
        rightmax[n-1]=height[n-1];
        for(int i=1;i<n;i++){
            leftmax[i]=max(height[i-1],leftmax[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            rightmax[i]=max(rightmax[i+1],height[i+1]);
        }
        int totaltrapped = 0;
        for(int i=0;i<n;i++){
            int trapped = min(leftmax[i],rightmax[i])-height[i];
            if(trapped>0) totaltrapped+=trapped;
        }
        return totaltrapped;
    }
};