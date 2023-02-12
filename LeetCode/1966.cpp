class Solution {
public:
    int binarySearchableNumbers(vector<int> &a) {
        vector<int> greaterLeft(a.size());
        int maxValue = a[0];
        for (int i = 1; i < a.size(); i++) {
            greaterLeft[i] = maxValue > a[i];
            maxValue = max(maxValue, a[i]);
        }
        
        vector<int> lessRight(a.size());
        int minValue = a[a.size() - 1];
        for (int i = (int)a.size() - 2; i >= 0; i--) {
            lessRight[i] = minValue < a[i];
            minValue = min(minValue, a[i]);
        }

        int res = 0;
        for (int i = 0; i < a.size(); i++)
            res += !greaterLeft[i] && !lessRight[i];
        return res;
    }
};