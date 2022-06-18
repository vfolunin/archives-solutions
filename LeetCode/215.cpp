class Solution {
public:
    int findKthLargest(vector<int> &a, int k) {
        nth_element(a.begin(), a.end() - k, a.end());
        return a[a.size() - k];
    }
};