class Solution {
public:
    int search(const ArrayReader &reader, int target) {
        int l = 0, r = 1;

        while (reader.get(r) <= target)
            r *= 2;

        while (l <= r) {
            int m = l + (r - l) / 2;
            int value = reader.get(m);

            if (value == target)
                return m;
            else if (value < target)
                l = m + 1;
            else
                r = m - 1;
        }

        return -1;
    }
};