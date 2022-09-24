class Solution {
public:
    int bestRotation(vector<int> &a) {
        vector<int> delta(a.size() + 1);
        
        for (int i = 0; i < a.size(); i++) {
            int lIndex = a[i];
            int rIndex = a.size() - 1;
            int lShift = (a.size() - (rIndex - i + a.size()) % a.size()) % a.size();
            int rShift = (a.size() - (lIndex - i + a.size()) % a.size()) % a.size();
            
            if (lShift <= rShift) {
                delta[lShift]++;
                delta[rShift + 1]--;
            } else {
                delta[0]++;
                delta[rShift + 1]--;
                delta[lShift]++;
                delta[a.size()]--;
            }
        }
        
        int res = 0, resSum = delta[0], curSum = delta[0];
        for (int i = 1; i < delta.size(); i++) {
            curSum += delta[i];
            if (resSum < curSum) {
                res = i;
                resSum = curSum;
            }
        }
        return res;
    }
};