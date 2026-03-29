class Solution {   
    bool isShift(vector<int> &a, vector<int> &b, int l, int r) {
        vector<int> p(r - l + 1);

        for (int i = 1; i < r - l + 1; i++) {
            int border = p[i - 1];
            while (border > 0 && b[l + i] != b[l + border])
                border = p[border - 1];
            p[i] = border + (b[l + i] == b[l + border]);
        }

        p.push_back(0);
        int prevBorder = p.back();
        
        for (int phase = 0; phase < 2; phase++) {
            for (int i = 0; i < r - l + 1; i++) {
                int border = prevBorder;
                while (border > 0 && a[l + i] != b[l + border])
                    border = p[border - 1];
                border += a[l + i] == b[l + border];

                if (border == r - l + 1)
                    return 1;

                prevBorder = border;
            }
        }

        return 0;
    }

    bool isSortable(vector<int> &a, vector<int> &b, int d) {
        for (int l = 0, r = d - 1; r < a.size(); l += d, r += d)
            if (!isShift(a, b, l, r))
                return 0;
        return 1;
    }

public:
    int sortableIntegers(vector<int> &a) {
        vector<int> b = a;
        sort(b.begin(), b.end());

        int res = 0;
        for (int d = 1; d * d <= a.size(); d++) {
            if (a.size() % d == 0) {
                if (isSortable(a, b, d))
                    res += d;
                if (d * d < a.size() && isSortable(a, b, a.size() / d))
                    res += a.size() / d;
            }
        }
        return res;
    }
};