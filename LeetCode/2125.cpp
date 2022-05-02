class Solution {
public:
    int numberOfBeams(vector<string> &a) {
        int res = 0;
        for (int i = 0, prevCount = 0; i < a.size(); i++) {
            int curCount = count(a[i].begin(), a[i].end(), '1');
            if (curCount) {
                res += prevCount * curCount;
                prevCount = curCount;
            }
        }
        return res;
    }
};