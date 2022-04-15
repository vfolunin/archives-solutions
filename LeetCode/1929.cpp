class Solution {
public:
    vector<int> getConcatenation(vector<int> &a) {
        a.insert(a.end(), a.begin(), a.end());
        return a;
    }
};