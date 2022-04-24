class Solution {
public:
    int findFinalValue(vector<int> &a, int target) {
        sort(a.begin(), a.end());
        while (binary_search(a.begin(), a.end(), target))
            target *= 2;
        return target;
    }
};