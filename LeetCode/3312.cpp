class Solution {
public:
    vector<int> gcdValues(vector<int> &a, vector<long long> &queries) {
        vector<int> divisorCount(*max_element(a.begin(), a.end()) + 1);
        for (int value : a) {
            for (int d = 1; d * d <= value; d++) {
                if (value % d == 0) {
                    divisorCount[d]++;
                    if (d * d < value)
                        divisorCount[value / d]++;
                }
            }
        }

        vector<long long> gcdCount(divisorCount.size());
        for (int i = gcdCount.size() - 1; i; i--) {
            gcdCount[i] = divisorCount[i] * (divisorCount[i] - 1LL) / 2;
            for (int j = i * 2; j < gcdCount.size(); j += i)
                gcdCount[i] -= gcdCount[j];
        }

        partial_sum(gcdCount.begin(), gcdCount.end(), gcdCount.begin());

        vector<int> res(queries.size());
        for (int i = 0; i < res.size(); i++)
            res[i] = upper_bound(gcdCount.begin(), gcdCount.end(), queries[i]) - gcdCount.begin();
        return res;
    }
};