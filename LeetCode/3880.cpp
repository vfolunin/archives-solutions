class Solution {
public:
    int minAbsoluteDifference(vector<int> &a) {
        int res = 1e9;
        for (int i = 0; i < a.size(); i++)
            for (int j = 0; j < a.size(); j++)
                if (a[i] == 1 && a[j] == 2 && res > abs(i - j))
                    res = abs(i - j);
        return res != 1e9 ? res : -1;
    }
};