class Solution {
public:
    int maxScore(vector<int> &a) {
        int minSum = 1e9;
        if (a.size() % 2) {
            minSum = *min_element(a.begin(), a.end());
        } else {
            for (int i = 0; i + 1 < a.size(); i++)
                minSum = min(minSum, a[i] + a[i + 1]);
        }
        return accumulate(a.begin(), a.end(), 0) - minSum;
    }
};