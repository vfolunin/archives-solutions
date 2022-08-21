class Solution {
public:
    string kthLargestNumber(vector<string> &a, int k) {
        k--;
        nth_element(a.begin(), a.begin() + k, a.end(), [](string &a, string &b) {
            if (a.size() != b.size())
                return a.size() > b.size();
            return a > b;
        });
        return a[k];
    }
};