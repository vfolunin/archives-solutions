class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &a) {
        int h = a.dimensions()[0], w = a.dimensions()[1];
        int y = 0, x = w - 1;

        while (y < h && x >= 0) {
            if (a.get(y, x))
                x--;
            else
                y++;
        }

        return x < w - 1 ? x + 1 : -1;
    }
};