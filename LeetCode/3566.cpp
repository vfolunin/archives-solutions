class Solution {
public:
    bool checkEqualPartitions(vector<int> &a, long long target) {
        for (int mask = 1; mask < (1 << a.size()) - 1; mask++) {
            vector<long long> product(2, 1);
            for (int bit = 0; bit < a.size() && product[0] <= target && product[1] <= target; bit++)
                product[(mask >> bit) & 1] *= a[bit];

            if (product[0] == target && product[1] == target)
                return 1;
        }
        return 0;
    }
};