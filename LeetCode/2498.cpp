class Solution {
    bool can(vector<int> pos, int dist) {
        int minPos = pos.front(), maxPos = pos.back();
        vector<int> isRemoved(pos.size());

        for (int curPos = minPos; curPos < maxPos; ) {
            int nextIndex = upper_bound(pos.begin(), pos.end(), curPos + dist) - pos.begin() - 1;
            if (nextIndex < 0 || nextIndex == pos.size() || pos[nextIndex] <= curPos)
                return 0;

            isRemoved[nextIndex] = 1;
            curPos = pos[nextIndex];
        }

        for (int i = 0; i < pos.size(); i++)
            if (isRemoved[i])
                pos[i] = -1;
        pos.erase(remove(pos.begin(), pos.end(), -1), pos.end());

        reverse(pos.begin(), pos.end());
        for (int &p : pos)
            p = -p;

        for (int curPos = -maxPos; curPos < -minPos; ) {
            int nextIndex = upper_bound(pos.begin(), pos.end(), curPos + dist) - pos.begin() - 1;
            if (nextIndex < 0 || nextIndex == pos.size() || pos[nextIndex] <= curPos)
                return 0;

            curPos = pos[nextIndex];
        }

        return 1;
    }

public:
    int maxJump(vector<int> &pos) {
        int l = 0, r = 1e9;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (can(pos, m))
                r = m;
            else
                l = m;
        }
        return r;
    }
};