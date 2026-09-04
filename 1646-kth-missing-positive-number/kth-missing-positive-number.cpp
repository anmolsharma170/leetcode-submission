class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_set<int> st;
        int count = 0;
        int n = arr.size();
        int end = arr[n-1];
        for(auto ele: arr) st.insert(ele);
        for(int i = 1;i<=end;i++){
            if(st.find(i)==st.end()){
                cout<<"inside1 "<<i<<endl;
                st.insert(i);
                count++;
                cout<<"Count increased"<<count<<endl;
            } 
            else{
                cout<<"inside2 "<<i<<endl;
            } 
            if(count==k) return i;
        }
        if(count!=0) return end-count+k;
        if(count==0) return end+k;
        return -1;
    }
};