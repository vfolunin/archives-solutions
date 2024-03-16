class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int> &a, vector<vector<int>> &queries) {
        set<pair<int, int>> unmarked;
        long long unmarkedSum = 0;

        for (int i = 0; i < a.size(); i++) {
            unmarked.insert({ a[i], i });
            unmarkedSum += a[i];
        }

        vector<long long> res(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            int index = queries[i][0], k = queries[i][1];

            if (unmarked.count({ a[index], index })) {
                unmarkedSum -= a[index];
                unmarked.erase({ a[index], index });
            }

            for (int j = 0; j < k && !unmarked.empty(); j++) {
                unmarkedSum -= unmarked.begin()->first;
                unmarked.erase(unmarked.begin());
            }

            res[i] = unmarkedSum;
        }
        return res;
    }
};