class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> vowels = {'a','e','i','o','u'};
        int count = 0;
        for(int i=0;i<k;i++){
            if(vowels.contains(s[i])) count++; 
        }
        int finalCount = count;

        for(int i=k;i<s.length();i++){
            if(vowels.contains(s[i])) count++;
            if(vowels.contains(s[i-k])) count--;
            if(count>finalCount) finalCount = count;     
        }
        return finalCount;
    }
};