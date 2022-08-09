class Solution {
public:
    int minOperations(vector<int> &a, vector<int> &b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        int aSum = 0;
        for (int value : a)
            aSum += value;
        
        int bSum = 0;
        for (int value : b)
            bSum += value;
        
        int delta, res = 0;
        if (aSum < bSum) {
            delta = bSum - aSum;
            for (int ai = 0, bi = b.size() - 1; delta > 0 && (ai < a.size() || bi >= 0); ) {
                if (ai < a.size() && (bi < 0 || 6 - a[ai] >= b[bi] - 1))
                    delta -= 6 - a[ai++];
                else
                    delta -= b[bi--] - 1;
                res++;
            }
        } else {
            delta = aSum - bSum;
            for (int ai = a.size() - 1, bi = 0; delta > 0 && (ai >= 0 || bi < b.size()); ) {
                if (ai >= 0 && (bi == b.size() || a[ai] - 1 >= 6 - b[bi]))
                    delta -= a[ai--] - 1;
                else
                    delta -= 6 - b[bi++];
                res++;
            }
        }
        return delta <= 0 ? res : -1;
    }
};