class Solution {
public:
    int countDominantElements(vector<int> &a) {
        int res = 0;
        for (int i = 0; i < a.size(); i++) {
            int num = 0, den = 0;
            for (int j : { i - 1, i + 1 }) {
                if (0 <= j && j < a.size()) {
                    num += a[j];
                    den++;
                }
            }
            res += a[i] * den >= num;
        }
        return res;
    }
};