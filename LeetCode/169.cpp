class Solution {
public:
    int majorityElement(vector<int> &a) {
        nth_element(a.begin(), a.begin() + a.size() / 2, a.end());
        return a[a.size() / 2];
    }
};