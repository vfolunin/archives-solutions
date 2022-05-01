class Solution {
public:
    int repeatedNTimes(vector<int> &a) {
        nth_element(a.begin(), a.begin() + a.size() / 2 - 1, a.end());
        if (count(a.begin(), a.end(), a[a.size() / 2 - 1]) > 1)
            return a[a.size() / 2 - 1];
        
        nth_element(a.begin(), a.begin() + a.size() / 2, a.end());
        return a[a.size() / 2];
    }
};