class Solution {
public:
    string reverseWords(string s) {
        vector<string> vec;
        string str="";
        for(int i = 0;i<s.length();i++){
            if(s[i]==' '){
                if(str!="" && str.length()!=0) vec.push_back(str);
                str="";
            }
            else{
                str+=s[i];
            }
        }
        
        if(str.length()!=0)vec.push_back(str);
        for(int i= 0;i<vec.size();i++){
            cout<<"\n"<<vec[i]<<" ";
            cout<<vec[i].length();
        }
        reverse(vec.begin(),vec.end());
        string ans = "";
        for(int i = 0;i<vec.size();i++){
            string ith = vec[i];
            for(int j=0;j<ith.length();j++){
                ans+=ith[j];
            }
            if(i!=vec.size()-1) ans+=" ";
            // ans+=" ";
        }
        return ans;
    }
};