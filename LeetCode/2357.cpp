class Solution {
public:
    int minimumOperations(vector<int> &a) {
        set<int> s(a.begin(), a.end());
        s.erase(0);
        return s.size();
    }
};