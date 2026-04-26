class Solution {
public:
    vector<int> findValidElements(vector<int> &a) {
        vector<int> l = a;
        for (int i = 1; i < a.size(); i++)
            l[i] = max(l[i - 1], a[i]);

        vector<int> r = a;
        for (int i = (int)a.size() - 2; i >= 0; i--)
            r[i] = max(r[i + 1], a[i]);
        
        vector<int> res;
        for (int i = 0; i < a.size(); i++)
            if (!i || l[i - 1] < a[i] || i + 1 == a.size() || a[i] > r[i + 1])
                res.push_back(a[i]);
        return res;
    }
};