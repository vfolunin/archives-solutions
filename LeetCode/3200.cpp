class Solution {
    int getHeight(vector<int> count) {
        for (int i = 1; 1; i++) {
            if (count[i % 2] < i)
                return i - 1;
            count[i % 2] -= i;
        }
    }

public:
    int maxHeightOfTriangle(int a, int b) {
        return max(getHeight({ a, b }), getHeight({ b, a }));
    }
};