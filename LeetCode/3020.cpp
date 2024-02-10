class Solution {
public:
    int maximumLength(vector<int> &a) {
        unordered_map<long long, int> counts;
        for (int value : a)
            counts[value]++;
        
        int res = 0;
        if (counts.count(1)) {
            res = counts[1] - (counts[1] % 2 == 0);
            counts.erase(1);
        }

        for (auto [value, count] : counts) {
            long long power = value;
            int cur = 0;

            while (counts.count(power) && counts[power] >= 2) {
                power *= power;
                cur += 2;
            }

            if (counts.count(power))
                cur++;
            else
                cur--;

            res = max(res, cur);
        }

        return res;
    }
};