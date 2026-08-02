class Solution {
public:
    int maximumWidth(vector<int> &a) {
        unordered_map<int, int> count, sumCount;
        for (int value : a) {
            count[value]++;
            sumCount[value]++;
        }

        for (auto &[value1, count1] : count) {
            for (auto &[value2, count2] : count) {
                if (value1 < value2)
                    sumCount[value1 + value2] += min(count1, count2);
                else if (value1 == value2)
                    sumCount[value1 + value2] += count1 / 2;
            }
        }
        
        int res = 0;
        for (auto &[value, count] : sumCount)
            res = max(res, count);
        return res;
    }
};