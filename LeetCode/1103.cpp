class Solution {
public:
    vector<int> distributeCandies(int candies, int size) {
        vector<int> res(size);
        for (int i = 0, count = 1; candies; i = (i + 1) % size, count++) {
            count = min(count, candies);
            res[i] += count;
            candies -= count;
        }
        return res;
    }
};