class Solution {
public:
    vector<int> findIndices(vector<int> &a, int indexDiff, int valueDiff) {
        for (int i = 0; i < a.size(); i++)
            for (int j = i + indexDiff; j < a.size(); j++)
                if (abs(a[i] - a[j]) >= valueDiff)
                    return { i, j };
        return { -1, -1 };
    }
};