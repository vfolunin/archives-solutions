class Solution {
public:
    int minKBitFlips(vector<int> a, int width) {
        vector<int> flipFrom(a.size() + 1);
        int res = 0;

        for (int i = 0, flip = 0; i < a.size(); i++) {
            flip ^= flipFrom[i];
            if ((a[i] ^ flip) == 0) {
                res++;
                if (i + width <= a.size()) {
                    flip ^= 1;
                    flipFrom[i + width] ^= 1;
                } else {
                    return -1;
                }
            }
        }

        return res;
    }
};