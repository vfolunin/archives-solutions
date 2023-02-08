class Solution {
public:
    void wiggleSort(vector<int> &a) {
        sort(a.begin(), a.end());
        vector<int> sorted = a;
        
        for (int ai = 0, si = 0, sj = (a.size() + 1) / 2; si < (a.size() + 1) / 2; si++, sj++) {
            a[ai++] = sorted[si];
            if (sj < a.size())
                a[ai++] = sorted[sj];
        }
    }
};