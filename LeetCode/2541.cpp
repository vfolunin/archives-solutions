class Solution {
public:
    long long minOperations(vector<int> &a, vector<int> &b, int delta) {
        if (!delta)
            return a == b ? 0 : -1;
        
        long long balance = 0, opCount = 0;

        for (int i = 0; i < a.size(); i++) {
            int diff = a[i] - b[i];
            if (diff % delta)
                return -1;

            int ops = diff / delta;
            balance += ops;
            if (ops > 0)
                opCount += ops;
        }

        return balance ? -1 : opCount;
    }
};