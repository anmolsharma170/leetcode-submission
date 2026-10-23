class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int whiteCount = 0;
        for(int i=0;i<k;i++){
            if(blocks[i]=='W') whiteCount++;
        }
        int minCount = whiteCount;
        for(int i=k;i<blocks.size();i++){
            if(blocks[i]=='W') whiteCount++;
            if(blocks[i-k]=='W') whiteCount--;
            if(whiteCount<minCount) minCount=whiteCount;
        }
        return minCount;
    }
};