class Solution {
    int getMinExistingDivisor(int value, unordered_set<int> &values, unordered_map<int, int> &memo) {
        if (auto it = memo.find(value); it != memo.end())
            return it->second;
        int &res = memo[value] = value;
        for (int divisor = 1; divisor * divisor <= value; divisor++)
            if (value % divisor == 0)
                for (int candidate : { divisor, value / divisor })
                    if (values.count(candidate))
                        res = min(res, candidate);
        return res;
    }

public:
    long long minArraySum(vector<int> &a) {
        unordered_set<int> values(a.begin(), a.end());
        unordered_map<int, int> memo;

        long long res = 0;
        for (int value : a)
            res += getMinExistingDivisor(value, values, memo);
        return res;
    }
};
