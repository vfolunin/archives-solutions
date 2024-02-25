class Solution {
public:
    bool isPossibleToSplit(vector<int> &a) {
        unordered_map<int, int> count;
        for (int value : a)
            if (++count[value] > 2)
                return 0;
        return 1;
    }
};