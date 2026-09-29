class Solution {
public:
    int maxTransactions(vector<int> &a) {
        long long sum = 0;
        multiset<int> values;

        for (int value : a) {
            sum += value;
            values.insert(value);

            while (sum < 0) {
                sum -= *values.begin();
                values.erase(values.begin());
            }
        }

        return values.size();
    }
};