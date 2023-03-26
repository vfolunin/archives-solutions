class Solution {
public:
    vector<long long> minOperations(vector<int> &a, vector<int> &queries) {
        sort(a.begin(), a.end());

        vector<long long> pl(a.size());
        for (int i = 0; i < a.size(); i++)
            pl[i] = a[i] + (i ? pl[i - 1] : 0);

        vector<long long> pr(a.size());
        for (int i = a.size() - 1; i >= 0; i--)
            pr[i] = a[i] + (i + 1 < a.size() ? pr[i + 1] : 0);

        vector<long long> res(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            int index = upper_bound(a.begin(), a.end(), queries[i]) - a.begin();
            if (index)
                res[i] += 1LL * index * queries[i] - pl[index - 1];
            if (index < a.size())
                res[i] += pr[index] - (a.size() - index) * queries[i];
        }
        return res;
    }
};