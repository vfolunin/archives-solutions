class Solution {
public:
    long long minIncrease(vector<int> &a) {
        vector<pair<int, long long>> res(a.size());
        res[1] = { 1, max(max(a[0], a[2]) - a[1] + 1, 0) };

        for (int i = 2; i + 1 < a.size(); i++) {
            res[i] = res[i - 1];

            pair<int, long long> candidate = res[i - 2];
            if (res[i].first < candidate.first || res[i].first == candidate.first && res[i].second > candidate.second)
                res[i] = candidate;

            candidate = { res[i - 2].first + 1, res[i - 2].second + max(max(a[i - 1], a[i + 1]) - a[i] + 1, 0) };
            if (res[i].first < candidate.first || res[i].first == candidate.first && res[i].second > candidate.second)
                res[i] = candidate;
        }
        
        return res[a.size() - 2].second;
    }
};