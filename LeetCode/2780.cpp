class Solution {
public:
    int minimumIndex(vector<int> &a) {
        unordered_map<int, int> count;
        int dominantValue = a[0];
        for (int value : a) {
            count[value]++;
            if (count[dominantValue] < count[value])
                dominantValue = value;
        }

        int lCount = 0, rCount = count[dominantValue];
        for (int i = 0; i + 1 < a.size(); i++) {
            lCount += a[i] == dominantValue;
            rCount -= a[i] == dominantValue;
            if (lCount * 2 > (i + 1) && rCount * 2 > (a.size() - i - 1))
                return i;
        }
        return -1;
    }
};