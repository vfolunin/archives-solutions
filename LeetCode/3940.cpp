class Solution {
public:
    vector<int> limitOccurrences(vector<int> &a, int limit) {
        vector<int> res;
        int count = 0;

        for (int value : a) {
            if (res.empty() || res.back() != value) {
                res.push_back(value);
                count = 1;
            } else if (count < limit) {
                res.push_back(value);
                count++;
            }
        }

        return res;
    }
};