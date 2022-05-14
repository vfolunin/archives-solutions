class Solution {
public:
    int getMaxLen(vector<int> &a) {
        int posLen = 0, negLen = 0, res = 0;
        
        for (int value : a) {
            if (value > 0) {
                posLen++;
                negLen += (bool)negLen;
            } else if (value < 0) {
                swap(posLen, negLen);
                negLen++;
                posLen += (bool)posLen;
            } else {
                posLen = negLen = 0;
            }
            
            res = max(res, posLen);
        }
        
        return res;
    }
};