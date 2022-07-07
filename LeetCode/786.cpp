class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int> &values, int k) {
        vector<pair<int, int>> pairs;
        for (int ni = 0; ni < values.size(); ni++)
            for (int di = ni + 1; di < values.size(); di++)
                pairs.push_back({ ni, di });
        
        nth_element(pairs.begin(), pairs.begin() + k - 1, pairs.end(), [&](auto &a, auto &b) {
            return values[a.first] * values[b.second] < values[b.first] * values[a.second];
        });
        return { values[pairs[k - 1].first], values[pairs[k - 1].second] };
    }
};