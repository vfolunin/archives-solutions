class Solution {
public:
    int minLights(vector<int> &a) {
        for (int i = 0, to = -1; i < a.size(); i++) {
            if (a[i])
                to = max(to, i + a[i]);
            else if (i <= to)
                a[i] = -1;
        }

        for (int i = a.size() - 1, to = a.size(); i >= 0; i--) {
            if (a[i])
                to = min(to, i - a[i]);
            else if (to <= i)
                a[i] = -1;
        }

        int res = 0;
        for (int i = 0, to = -1; i < a.size(); i++) {
            if (!a[i] && to < i) {
                res++;
                to = i + 2;
            }
        }
        return res;
    }
};