class Solution {
public:
    int minTaps(int width, vector<int> &a) {
        vector<pair<int, int>> segments;
        for (int i = 0; i < a.size(); i++)
            segments.push_back({ i - a[i], i + a[i] });

        sort(segments.begin(), segments.end());

        int to = 0, nextTo = 0, count = 0;

        for (auto &[l, r] : segments) {
            if (to < l) {
                to = nextTo;
                count++;
                if (to >= width)
                    return count;
                if (to < l)
                    return -1;
            }
            nextTo = max(nextTo, r);
        }

        return nextTo >= width ? count + 1 : -1;
    }
};