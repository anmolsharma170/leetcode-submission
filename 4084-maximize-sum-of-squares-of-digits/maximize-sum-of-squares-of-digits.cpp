class Solution {
public:
    
    string maxSumOfSquares(int num, int sum) {
        string numlen = to_string(num);
        // string sumlen = to_string(sum);
        // if(sumlen.length()>numlen.length()) return ""; 
        string ansstr = "";
        int ans = 0;
        if(sum<10){
            ans+=sum;
            ansstr = to_string(ans);
            while(ansstr.length()<num){
                ansstr+="0";
            }
            return ansstr;
        }
        while(ans<sum){ 
            int tempsum = ans+9;             //ansstr.length()!=num
            if(tempsum<sum){
                ansstr+="9";
                ans+=9;
            } 
            else {
                int x = sum-ans;
                ans+=x;
                ansstr+=to_string(x);
            }
        }
        if(ansstr.length()>num) return "";
        while(ansstr.length()<num) ansstr+="0";
        return ansstr;
    }
};