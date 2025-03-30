class Solution {
public:
    int maxContainers(int size, int weight, int limit) {
        return min(size * size, limit / weight);
    }
};