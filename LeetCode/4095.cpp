class Solution {
public:
    int countStaircase(vector<int> &a) {
        vector<int> count(1e5 + 1), needCount(1e5 + 1);
        int res = 0;

        for (int l = 0; l < a.size(); l++) {
            int r = l, uniqueCount = 0, goodCount = 0;

            for ( ; r < a.size(); r++) {
                int value = a[r];

                if (!count[value])
                    needCount[value] = ++uniqueCount;

                if (++count[value] > needCount[value])
                    break;

                goodCount += count[value] == needCount[value];
                res += goodCount == uniqueCount;
            }

            for (int i = l; i <= r && i < a.size(); i++)
                count[a[i]] = 0;
        }

        return res;
    }
};