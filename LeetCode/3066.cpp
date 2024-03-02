class Solution {
public:
    int minOperations(vector<int> &a, int threshold) {
        multiset<long long> values(a.begin(), a.end());
        int res = 0;

        while (*values.begin() < threshold) {
            long long valueA = *values.begin();
            values.erase(values.begin());
            long long valueB = *values.begin();
            values.erase(values.begin());
            values.insert(valueA * 2 + valueB);
            res++;
        }

        return res;
    }
};