class Solution {
public:
    bool canJump(vector<int> &a) {
        for (int i = 0, to = 0; 1; i++) {
            to = max(to, i + a[i]);
            if (to >= a.size() - 1)
                return 1;
            if (i == to)
                return 0;
        }
    }
};