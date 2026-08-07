class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int i=n;i<INT_MAX;i++){
            int num = 1;
            int x = i;
            while(x>0){
                int last = x%10;
                num*=last;
                x/=10;
            }
            if(num%t==0) return i;
            
        }
        return 0;
    }
};