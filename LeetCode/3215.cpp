class Solution {
    int ones(int n) {
        int res = 0;
        while (n) {
            res++;
            n &= n - 1;
        }
        return res;
    }

public:
    long long tripletCount(vector<int> &a, vector<int> &b, vector<int> &c) {
        vector<long long> aCount(2);
        for (int value : a)
            aCount[ones(value) % 2]++;
        
        vector<long long> bCount(2);
        for (int value : b)
            bCount[ones(value) % 2]++;
        
        vector<long long> cCount(2);
        for (int value : c)
            cCount[ones(value) % 2]++;
        
        return aCount[0] * bCount[0] * cCount[0] +
               aCount[0] * bCount[1] * cCount[1] +
               aCount[1] * bCount[0] * cCount[1] +
               aCount[1] * bCount[1] * cCount[0];
    }
};