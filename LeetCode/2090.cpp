class Solution {
public:
    vector<int> getAverages(vector<int> &a, int size) {
        size = 2 * size + 1;
        long long sum = accumulate(a.begin(), min(a.end(), a.begin() + size - 1), 0LL);
        
        vector<int> res(a.size(), -1);
        for (int l = 0, r = size - 1; r < a.size(); l++, r++) {
            sum += a[r];
            res[(l + r) / 2] = sum / size;
            sum -= a[l];
        }
        return res;
    }
};