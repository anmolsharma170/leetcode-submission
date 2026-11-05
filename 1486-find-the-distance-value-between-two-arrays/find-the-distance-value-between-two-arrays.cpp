class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int count  = 0;
        unordered_set<int> s;
        for(int i=0;i<arr1.size();i++){
            for(int j = 0;j<arr2.size();j++){
                int ans = arr1[i]-arr2[j];
                if(abs(ans)<=d){
                    count++;
                    cout<<ans<<" "<<i<<endl;
                    s.insert(i);
                    
                }
            }
        }
        return arr1.size()-s.size();
    }
};