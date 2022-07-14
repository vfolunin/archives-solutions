class Solution {
    double x, y, r;
    
public:
    Solution(double r, double x, double y) : x(x), y(y), r(r) {}
    
    vector<double> randPoint() {
        static minstd_rand gen;
        static uniform_real_distribution<double> distr(0, 1);
        
        double angle = distr(gen) * 2 * acos(-1);
        double size = sqrt(distr(gen)) * r;
        
        return { x + cos(angle) * size, y + sin(angle) * size };
    }
};