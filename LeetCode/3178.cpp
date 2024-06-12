class Solution {
public:
    int numberOfChild(int size, int index) {
        index %= (size - 1) * 2;
        if (index < size)
            return index;
        else
            return 2 * (size - 1) - index;
    }
};