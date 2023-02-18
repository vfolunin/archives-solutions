class Solution {
public:
    int minImpossibleOR(vector<int> &a) {
        unordered_set<int> values(a.begin(), a.end());
        for (int value = 1; 1; value *= 2)
            if (!values.count(value))
                return value;
    }
};