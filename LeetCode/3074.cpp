class Solution {
public:
    int minimumBoxes(vector<int> &a, vector<int> &b) {
        int sum = accumulate(a.begin(), a.end(), 0);
        sort(b.rbegin(), b.rend());

        for (int i = 0; i < b.size(); i++) {
            if (sum <= b[i])
                return i + 1;
            sum -= b[i];
        }

        return -1;
    }
};