class Solution {
public:
    int getCommon(vector<int> &a, vector<int> &b) {
        for (int value : a)
            if (binary_search(b.begin(), b.end(), value))
                return value;
        return -1;
    }
};