class Solution {
public:
    vector<int> findArray(vector<int> &p) {
        vector<int> a(p.size());
        for (int i = 0; i < a.size(); i++)
            a[i] = p[i] ^ (i ? p[i - 1] : 0);
        return a;
    }
};