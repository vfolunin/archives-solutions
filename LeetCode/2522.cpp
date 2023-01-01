class Solution {
public:
    int minimumPartition(string s, long long limit) {
        int res = 1;
        long long value = 0;
        for (char c : s) {
            if (value * 10 + c - '0' <= limit) {
                value = value * 10 + c - '0';
            } else if (c - '0' > limit) {
                return -1;
            } else {
                value = c - '0';
                res++;
            }
        }
        return res;
    }
};