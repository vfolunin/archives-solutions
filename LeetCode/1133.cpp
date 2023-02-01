class Solution {
public:
    int largestUniqueNumber(vector<int> &a) {
        unordered_map<int, int> count;
        for (int value : a)
            count[value]++;

        int res = -1;
        for (auto &[value, count] : count)
            if (count == 1)
                res = max(res, value);
        return res;
    }
};