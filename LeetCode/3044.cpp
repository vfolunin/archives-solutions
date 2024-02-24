class Solution {
        bool isPrime(int n) {
        if (n < 2)
            return 0;
        
        for (long long d = 2; d * d <= n; d++)
            if (n % d == 0)
                return 0;
        
        return 1;
    }

public:
    int mostFrequentPrime(vector<vector<int>> &a) {
        int h = a.size(), w = a[0].size();

        vector<int> dy = { -1, -1, -1, 0, 1, 1, 1, 0 };
        vector<int> dx = { -1, 0, 1, 1, 1, 0, -1, -1 };

        map<int, int> count;
        int maxCount = 0;

        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                for (int d = 0; d < dy.size(); d++) {
                    int value = 0;
                    
                    for (int step = 0; 1; step++) {
                        int ty = y + dy[d] * step;
                        int tx = x + dx[d] * step;
                        if (ty < 0 || ty == h || tx < 0 || tx == w)
                            break;

                        value = value * 10 + a[ty][tx];
                        if (value > 9 && isPrime(value))
                            maxCount = max(maxCount, ++count[value]);
                    }
                }
            }
        }

        int res = -1;
        for (auto &[value, count] : count)
            if (count == maxCount)
                res = value;
        return res;
    }
};