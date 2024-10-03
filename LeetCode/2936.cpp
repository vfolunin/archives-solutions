class Solution {
public:
    int countBlocks(BigArray *a) {
        int res = 0;
        for (long long from = 0; from < a->size(); ) {
            long long l = from, r = a->size();
            while (l + 1 < r) {
                long long m = l + (r - l) / 2;
                if (a->at(from) == a->at(m))
                    l = m;
                else
                    r = m;
            }
            from = r;
            res++;
        }
        return res;
    }
};