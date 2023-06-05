class Solution {
public:
    int semiOrderedPermutation(vector<int> &a) {
        int frontPos = find(a.begin(), a.end(), 1) - a.begin();
        int backPos = find(a.begin(), a.end(), a.size()) - a.begin();
        return frontPos + a.size() - 1 - backPos - (backPos < frontPos);
    }
};