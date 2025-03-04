class Solution {
public:
    vector<int> transformArray(vector<int> &a) {
        for (int &value : a)
            value %= 2;
        sort(a.begin(), a.end());
        return a;
    }
};