class Solution {
public:
    vector<int> findIndices(vector<int> &a, int indexDiff, int valueDiff) {
        vector<int> lMin(a.size()), lMax(a.size());
        for (int i = 1; i < a.size(); i++) {
            lMin[i] = a[i] < a[lMin[i - 1]] ? i : lMin[i - 1];
            lMax[i] = a[i] > a[lMax[i - 1]] ? i : lMax[i - 1];
        }
        
        for (int i = indexDiff; i < a.size(); i++)
            for (int j : { lMin[i - indexDiff], lMax[i - indexDiff] })
                if (abs(a[i] - a[j]) >= valueDiff)
                    return { i, j };
        return { -1, -1 };
    }
};