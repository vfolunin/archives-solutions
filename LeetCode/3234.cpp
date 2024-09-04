class Solution {
public:
    int numberOfSubstrings(string &s) {
        vector<int> zeroPos;
        for (int i = 0; i < s.size(); i++)
            if (s[i] == '0')
                zeroPos.push_back(i);
        zeroPos.push_back(s.size());

        int maxZeroCount = sqrt(s.size());
        int res = 0;

        for (int i = 0; i < s.size(); i++) {
            int zeroPosIndex = lower_bound(zeroPos.begin(), zeroPos.end(), i) - zeroPos.begin();
            res += zeroPos[zeroPosIndex] - i;

            for (int zeroCount = 1; zeroCount <= maxZeroCount && zeroPosIndex + zeroCount < zeroPos.size(); zeroCount++) {
                int l = max(zeroPos[zeroPosIndex + zeroCount - 1], i + zeroCount + zeroCount * zeroCount - 1);
                int r = zeroPos[zeroPosIndex + zeroCount] - 1;
                res += max(r - l + 1, 0);
            }
        }

        return res;
    }
};