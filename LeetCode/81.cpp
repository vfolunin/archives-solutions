class Solution {
public:
    bool search(vector<int> &a, int target) {
        return find(a.begin(), a.end(), target) != a.end();
    }
};