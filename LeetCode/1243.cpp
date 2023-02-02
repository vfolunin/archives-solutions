class Solution {
    vector<int> transform(vector<int> &a) {
        vector<int> res = a;
        for (int i = 1; i + 1 < a.size(); i++) {
            if (a[i - 1] > a[i] && a[i] < a[i + 1])
                res[i]++;
            if (a[i - 1] < a[i] && a[i] > a[i + 1])
                res[i]--;
        }
        return res;
    }

public:
    vector<int> transformArray(vector<int> &a) {
        while (1) {
            vector<int> b = transform(a);
            if (a == b)
                return a;
            a = b;
        }
    }
};