class Solution {
    int ones(int n) {
        int res = 0;
        while (n) {
            res++;
            n &= n - 1;
        }
        return res;
    }

public:
    bool canSortArray(vector<int> &a) {
        vector<int> part = { a[0] }, res;

        for (int i = 1; i < a.size(); i++) {
            if (ones(part.back()) == ones(a[i])) {
                part.push_back(a[i]);
            } else {
                sort(part.begin(), part.end());
                res.insert(res.end(), part.begin(), part.end());
                part = { a[i] };
            }
        }
        sort(part.begin(), part.end());
        res.insert(res.end(), part.begin(), part.end());

        return is_sorted(res.begin(), res.end());
    }
};