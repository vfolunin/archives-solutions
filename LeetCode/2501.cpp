class Solution {
public:
    int longestSquareStreak(vector<int> &a) {
        sort(a.begin(), a.end());

        unordered_map<int, int> lisSize;
        int res = -1;

        for (int lastValue : a) {
            lisSize[lastValue] = 1;
            int prevValue = sqrt(lastValue);
            if (prevValue * prevValue == lastValue && lisSize.count(prevValue)) {
                lisSize[lastValue] = max(lisSize[lastValue], lisSize[prevValue] + 1);
                res = max(res, lisSize[lastValue]);
            }
        }

        return res;
    }
};