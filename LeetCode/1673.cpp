class Solution {
public:
    vector<int> mostCompetitive(vector<int> &a, int k) {
        vector<int> res;
        for (int i = 0; i < a.size(); i++) {
            while (!res.empty() && res.back() > a[i] && res.size() + a.size() - i > k)
                res.pop_back();
            if (res.size() < k)
                res.push_back(a[i]);
        }
        return res;
    }
};