class Solution {
public:
    int maxDifference(string &s, int minSize) {
        int res = -1e9;

        for (char c0 = '0'; c0 <= '4'; c0++) {
            for (char c1 = '0'; c1 <= '4'; c1++) {
                int count0 = 0, count1 = 0, prevCount0 = 0, prevCount1 = 0;
                vector<int> prevMin(4, 1e9);

                for (int l = -1, r = 0; r < s.size(); r++) {
                    count0 += s[r] == c0;
                    count1 += s[r] == c1;

                    while (l + minSize <= r && prevCount0 + 2 <= count0) {
                        int prevMask = prevCount0 % 2 * 2 + prevCount1 % 2;
                        prevMin[prevMask] = min(prevMin[prevMask], prevCount1 - prevCount0);

                        l++;
                        prevCount0 += s[l] == c0;
                        prevCount1 += s[l] == c1;
                    }

                    int curMask = count0 % 2 * 2 + count1 % 2;
                    res = max(res, count1 - count0 - prevMin[curMask ^ 1]);
                }
            }
        }

        return res;
    }
};