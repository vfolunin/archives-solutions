class Solution {
    long long c2(long long n) {
        return n * (n - 1) / 2;
    }

public:
    int subsequencesWithMiddleMode(vector<int> &a) {
        unordered_set<int> values(a.begin(), a.end());
        long long lSize = 0, rSize = a.size();
        unordered_map<int, long long> lCount, rCount;
        for (int value : a)
            rCount[value]++;
        
        long long res = 0;

        for (int value : a) {
            values.erase(value);
            rSize--;
            rCount[value]--;

            res += c2(lSize) * c2(rSize);
            res -= c2(lSize - lCount[value]) * c2(rSize - rCount[value]);

            for (int otherValue : values) {
                res -= c2(lCount[otherValue]) * rCount[value] * (rSize - rCount[value] - rCount[otherValue]);
                res -= lCount[value] * (lSize - lCount[value] - lCount[otherValue]) * c2(rCount[otherValue]);
                res -= lCount[value] * lCount[otherValue] * rCount[otherValue] * (rSize - rCount[value] - rCount[otherValue]);
                res -= (lSize - lCount[value] - lCount[otherValue]) * lCount[otherValue] * rCount[value] * rCount[otherValue];

                res -= c2(lCount[otherValue]) * rCount[value] * rCount[otherValue];
                res -= lCount[value] * lCount[otherValue] * c2(rCount[otherValue]);
            }

            values.insert(value);
            lSize++;
            lCount[value]++;
        }
        
        return res % (long long)(1e9 + 7);
    }
};