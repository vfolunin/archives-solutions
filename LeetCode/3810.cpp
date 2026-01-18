class Solution {
public:
    int minOperations(vector<int> &a, vector<int> &b) {
        unordered_set<int> values;
        for (int i = 0; i < a.size(); i++)
            if (a[i] != b[i])
                values.insert(a[i]);
        return values.size();
    }
};