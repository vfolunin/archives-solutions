class Solution {
    long long getSum(int size) {
        long long sum = 0;
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                sum += i | j;
        return sum * (size - 1) * size / 2;
    }

public:
    int maxSizedArray(long long limit) {
        int l = 0, r = 1;
        while (getSum(r) <= limit)
            r *= 2;
        
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (getSum(m) <= limit)
                l = m;
            else
                r = m;
        }

        return l;
    }
};