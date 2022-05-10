class Solution {
public:
    vector<int> replaceElements(vector<int> &a) {
        int maxValue = -1;
        for (int i = a.size() - 1; i >= 0; i--) {
            int nextMaxValue = max(a[i], maxValue);
            a[i] = maxValue;
            maxValue = nextMaxValue;
        }
        return a;
    }
};