class Solution {
public:
    int minSensors(int h, int w, int d) {
        d = d * 2 + 1;
        return ((h + d - 1) / d) * ((w + d - 1) / d);
    }
};