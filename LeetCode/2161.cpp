class Solution {
public:
    vector<int> pivotArray(vector<int> &a, int pivot) {
        stable_partition(a.begin(), a.end(), [&](int value) { return value < pivot; });
        stable_partition(a.begin(), a.end(), [&](int value) { return value <= pivot; });
        return a;
    }
};