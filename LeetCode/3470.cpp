class Solution {
    long long getCount(vector<int> &prefix, int targetSize) {
        if (targetSize % 2 && !prefix.empty() && prefix[0] % 2 == 0)
            return 0;

        vector<int> valueCount(2);
        valueCount[0] = targetSize / 2;
        valueCount[1] = targetSize - valueCount[0];

        for (int value : prefix)
            valueCount[value % 2]--;

        long long res = 1;
        for (int valueCount : valueCount) {
            for (int i = 1; i <= valueCount; i++) {
                res *= i;
                if (res > 1e15)
                    return 1e15;
            }
        }
        return res;
    }

public:
    vector<int> permute(int targetSize, long long index) {
        index--;

        vector<int> values(targetSize);
        iota(values.begin(), values.end(), 1);

        vector<int> res;
        while (res.size() < targetSize) {
            bool found = 0;
            for (int i = 0; i < values.size(); i++) {
                if (res.empty() || res.back() % 2 != values[i] % 2) {
                    res.push_back(values[i]);
                    long long count = getCount(res, targetSize);
                    if (index >= count) {
                        index -= count;
                        res.pop_back();
                    } else {
                        values.erase(values.begin() + i);
                        found = 1;
                        break;
                    }
                }
            }
            if (!found)
                return {};
        }
        return res;
    }
};