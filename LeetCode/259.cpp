class Solution {
public:
    int threeSumSmaller(vector<int> &values, int target) {        
        target += 300;

        vector<int> count(201);
        for (int value : values)
            count[value + 100]++;
        
        vector<int> pCount = count;
        partial_sum(pCount.begin(), pCount.end(), pCount.begin());

        int res = 0;

        for (int a = 0; a < count.size(); a++) {
            if (a + a + a < target)
                res += count[a] * (count[a] - 1) * (count[a] - 2) / 6;

            for (int b = 0; b < count.size(); b++) {
                if (a != b && a + a + b < target)
                    res += count[a] * (count[a] - 1) / 2 * count[b];

                if (b < a) {
                    int to = min(b - 1, target - a - b - 1);
                    if (0 <= to)
                        res += count[a] * count[b] * pCount[to];
                }
            }
        }

        return res;
    }
};