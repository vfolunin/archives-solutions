class Solution {
public:
    int maxFreeTime(int size, vector<int> &l, vector<int> &r) {
        l.insert(l.begin(), 0);
        r.insert(r.begin(), 0);

        l.push_back(size);
        r.push_back(size);

        multiset<int> gaps = { 0 };
        for (int i = 2; i + 1 < l.size(); i++)
            gaps.insert(l[i + 1] - r[i]);

        int res = 0;
        for (int i = 1; i + 1 < l.size(); i++) {
            int width = r[i] - l[i];
            res = max(res, l[i + 1] - r[i - 1] - (width <= *gaps.rbegin() ? 0 : width));

            if (i + 2 < l.size())
                gaps.erase(gaps.find(l[i + 2] - r[i + 1]));
            gaps.insert(l[i] - r[i - 1]);
        }
        return res;
    }
};