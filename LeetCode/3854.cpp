class Solution {
    vector<int> solve(vector<int> a, bool type) {
        int ops = 0, minValue = 1e9, maxValue = -1e9;
        for (int i = 0; i < a.size(); i++) {
            ops += (i & 1) ^ (a[i] & 1) ^ type;
            minValue = min(minValue, a[i]);
            maxValue = max(maxValue, a[i]);
        }

        for (int i = 0; i < a.size(); i++) {
            if ((i & 1) ^ (a[i] & 1) ^ type) {
                if (a[i] == minValue)
                    a[i]++;
                else if (a[i] == maxValue)
                    a[i]--;
            }
        }

        auto [minIt, maxIt] = minmax_element(a.begin(), a.end());
        return { ops, *maxIt - *minIt };
    }

public:
    vector<int> makeParityAlternating(vector<int> &a) {
        return min(solve(a, 0), solve(a, 1));
    }
};