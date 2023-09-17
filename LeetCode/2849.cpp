class Solution {
public:
    bool isReachableAtTime(int x1, int y1, int x2, int y2, int moves) {
        int dist = max(abs(x1 - x2), abs(y1 - y2));
        return dist <= moves && (dist || moves != 1);
    }
};