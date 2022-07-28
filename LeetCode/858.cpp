class Solution {
public:
    int mirrorReflection(int a, int b) {
        int l = lcm(a, b);
        int ka = l / a;
        int kb = l / b;
        
        if (kb % 2 == 0)
            return 2;
        else if (ka % 2)
            return 1;
        else
            return 0;
    }
};