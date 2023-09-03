class Solution {
public:
    long long minimumPossibleSum(int size, int sum) {
        unordered_set<int> values;
        long long res = 0;

        for (long long value = 1; values.size() < size; value++) {
            while (values.count(sum - value))
                value++;

            values.insert(value);
            res += value;
        }

        return res;
    }
};