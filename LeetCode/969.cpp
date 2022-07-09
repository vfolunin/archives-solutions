class Solution {
public:
    vector<int> pancakeSort(vector<int> &a) {
        vector<int> res;
        for (int i = a.size() - 1; i; i--) {
            int m = max_element(a.begin(), a.begin() + i + 1) - a.begin();
            res.push_back(m + 1);
            reverse(a.begin(), a.begin() + m + 1);
            res.push_back(i + 1);
            reverse(a.begin(), a.begin() + i + 1);
        }
        return res;
    }
};