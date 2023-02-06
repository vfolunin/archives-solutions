class Solution {
public:
    int smallestCommonElement(vector<vector<int>> &a) {
        map<int, int> count;
        for (vector<int> &row : a)
            for (int value : row)
                count[value]++;

        for (auto &[value, count] : count)
            if (count == a.size())
                return value;
        return -1;
    }
};