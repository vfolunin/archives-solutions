class Solution {
public:
    int lengthOfLIS(vector<int> &a) {
        vector<int> last(1, -1e9);
        for (int value : a) {
            auto it = lower_bound(last.begin(), last.end(), value);
            if (it == last.end())
                last.push_back(value);
            else
                *it = value;
        }
        return last.size() - 1;
    }
};