class Solution {
public:
    vector<int> buildArray(vector<int> &p) {
        vector<int> a(p.size());
        for (int i = 0; i < a.size(); i++)
            a[i] = p[p[i]];
        return a;
    }
};