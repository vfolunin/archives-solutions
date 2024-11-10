class Solution {
    bool isIncreasing(vector<int> &a, int l, int r) {
        for (int i = l; i < r; i++)
            if (a[i] >= a[i + 1])
                return 0;
        return 1;
    }

public:
    bool hasIncreasingSubarrays(vector<int> &a, int width) {
        for (int i = 0; i + width * 2 <= a.size(); i++)
            if (isIncreasing(a, i, i + width - 1) && isIncreasing(a, i + width, i + width * 2 - 1))
                return 1;
        return 0;
    }
};