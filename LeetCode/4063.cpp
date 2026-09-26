class Solution {
    int getMaxSize(vector<int> &a, int divisor) {
        static static vector<int> pos(1e5);
        int remainder = 0, maxSize = 0;

        fill(pos.begin(), pos.begin() + divisor, -1e9);
        pos[remainder] = -1;

        for (int i = 0; i < a.size(); i++) {
            remainder = ((remainder + a[i]) % divisor + divisor) % divisor;
            if (pos[remainder] == -1e9)
                pos[remainder] = i;
            else
                maxSize = max(maxSize, i - pos[remainder]);
        }

        return maxSize;
    }

public:
    int longestSubarray(vector<int> &a, int divisor) {
        int maxSize = getMaxSize(a, divisor);

        for (int &value : a) {
            value = -value;
            maxSize = max(maxSize, getMaxSize(a, divisor));
            value = -value;
        }

        return maxSize;
    }
};