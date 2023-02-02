class Solution {
    bool isLeap(int y) {
        return y % 400 == 0 || y % 4 == 0 && y % 100;
    }
        
public:
    int numberOfDays(int y, int m) {
        static vector<int> d = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        return d[m] + (m == 2 && isLeap(y));
    }
};