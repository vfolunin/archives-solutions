class Solution {
    long long binPow(long long x, long long p, long long mod) {
        if (!p)
            return 1 % mod;
        if (p % 2)
            return binPow(x, p - 1, mod) * x % mod;
        long long r = binPow(x, p / 2, mod);
        return r * r % mod;
    }

public:
    int countEffective(vector<int> &a) {
        int targetOrSum = 0;
        for (int value : a)
            targetOrSum |= value;

        int bitCount = 0;
        while ((1 << bitCount) <= targetOrSum)
            bitCount++;

        vector<int> numOfValuesWhichAreSubmaskOf(1 << bitCount);
        for (int value : a)
            numOfValuesWhichAreSubmaskOf[value]++;

        for (int bit = 0; bit < bitCount; bit++)
            for (int mask = 0; mask < numOfValuesWhichAreSubmaskOf.size(); mask++)
                if (mask & (1 << bit))
                    numOfValuesWhichAreSubmaskOf[mask] += numOfValuesWhichAreSubmaskOf[mask ^ (1 << bit)];

        const long long MOD = 1e9 + 7;
        vector<long long> numOfSubsequencesWithOrSumEqualTo(1 << bitCount);
        for (int mask = 0; mask < numOfSubsequencesWithOrSumEqualTo.size(); mask++)
            numOfSubsequencesWithOrSumEqualTo[mask] = binPow(2, numOfValuesWhichAreSubmaskOf[mask], MOD);
            
        for (int bit = 0; bit < bitCount; bit++)
            for (int mask = 0; mask < numOfSubsequencesWithOrSumEqualTo.size(); mask++)
                if (mask & (1 << bit))
                    numOfSubsequencesWithOrSumEqualTo[mask] = (numOfSubsequencesWithOrSumEqualTo[mask] - numOfSubsequencesWithOrSumEqualTo[mask ^ (1 << bit)] + MOD) % MOD;

        long long res = 0;
    	for (int mask = 0; mask < targetOrSum; mask++)
            res = (res + numOfSubsequencesWithOrSumEqualTo[mask]) % MOD;
        return res;
    }
};