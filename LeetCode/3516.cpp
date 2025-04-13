class Solution {
public:
    int findClosest(int a, int b, int c) {
        int ac = abs(a - c);
        int bc = abs(b - c);
        
        if (ac == bc)
            return 0;
        else if (ac < bc)
            return 1;
        else
            return 2;
    }
};