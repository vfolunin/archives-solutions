class Solution {
    int solve(vector<int> a, vector<int> b) {
        int res = 0;

        if (a.back() > b.back()) {
            swap(a.back(), b.back());
            res++;
        }

        for (int i = 0; i + 1 < a.size(); i++) {
            if (a[i] > a.back()) {
                if (a[i] > b.back() || b[i] > a.back())
                    return -1;

                swap(a[i], b[i]);
                res++;
            }
        }

        return res;
    }

public:
    int minOperations(vector<int> &a, vector<int> &b) {
        return min(solve(a, b), solve(b, a));
    }
};