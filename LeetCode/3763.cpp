class Solution {
public:
    long long maxSum(vector<int> &a, vector<int> &limit) {
        vector<pair<int, int>> pairs;
        for (int i = 0; i < a.size(); i++)
            pairs.push_back({ limit[i], a[i] });
        sort(pairs.begin(), pairs.end());

        multiset<int> values;
        long long res = 0;
        for (int i = 0, step = 1; step <= a.size(); step++) {
            while (i < pairs.size() && pairs[i].first <= step) {
                values.insert(pairs[i].second);
                i++;
            }
            if (!values.empty()) {
                res += *prev(values.end());
                values.erase(prev(values.end()));
            } else {
                break;
            }
        }
        return res;
    }
};