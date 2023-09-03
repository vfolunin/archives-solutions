class Solution {
public:
    int minOperations(vector<int> &a, int mask) {
        if (accumulate(a.begin(), a.end(), 0LL) < mask)
            return -1;

        vector<int> powerCount(31);
        for (int i = 0; i < powerCount.size(); i++)
            powerCount[i] = count(a.begin(), a.end(), 1 << i);

        long long sum = 0;
        int res = 0;

        for (int i = 0; i < powerCount.size(); i++) {
            if (mask & (1 << i)) {
                if (sum >= (1 << i)) {
                    sum -= 1 << i;
                } else {
                    while (!powerCount[i]) {
                        int j = i + 1;
                        while (j < powerCount.size() && !powerCount[j])
                            j++;
                        
                        res++;
                        powerCount[j]--;
                        powerCount[j - 1] += 2;
                    }
                    powerCount[i]--;
                }
            }

            sum += powerCount[i] * (1LL << i);
        }

        return res;
    }
};