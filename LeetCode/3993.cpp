class Solution {
public:
    long long maximumValue(int size, int value, int limit) {
        if (size == 1)
            return value;
        return value + (size / 2) * (limit - 1LL) + 1;
    }
};