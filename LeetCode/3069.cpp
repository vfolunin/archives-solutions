class Solution {
public:
    vector<int> resultArray(vector<int> &a) {
        vector<int> l = { a[0] };
        vector<int> r = { a[1] };

        for (int i = 2; i < a.size(); i++) {
            if (l.back() > r.back())
                l.push_back(a[i]);
            else
                r.push_back(a[i]);
        }

        l.insert(l.end(), r.begin(), r.end());
        return l;
    }
};