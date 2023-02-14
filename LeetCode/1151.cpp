class Solution {
public:
    int minSwaps(vector<int> &a) {
        int windowSize = count(a.begin(), a.end(), 1), cur = 0;
        for (int i = 0; i < windowSize; i++)
            cur += !a[i];
        
        int res = cur;
        for (int i = windowSize; i < a.size(); i++) {
            cur -= !a[i - windowSize];
            cur += !a[i];
            res = min(res, cur);
        }
        return res;
    }
};