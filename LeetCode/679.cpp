class Solution {
    vector<double> getMoves(double a, double b) {
        vector<double> moves = { a + b, a - b, b - a, a * b };
        if (b)
            moves.push_back(a / b);
        if (a)
            moves.push_back(b / a);
        return moves;
    }
    
    bool rec(const vector<double> &a) {
        if (a.size() == 1)
            return fabs(a[0] - 24) < 1e-9;
        
        for (int i = 0; i < a.size(); i++) {
            for (int j = i + 1; j < a.size(); j++) {
                vector<double> b;
                for (int k = 0; k < a.size(); k++)
                    if (k != i && k != j)
                        b.push_back(a[k]);
                b.push_back(0);
                
                for (double value : getMoves(a[i], a[j])) {
                    b.back() = value;
                    if (rec(b))
                        return 1;
                }
            }
        }
        
        return 0;
    }
    
public:
    bool judgePoint24(vector<int> &a) {
        return rec(vector<double>(a.begin(), a.end()));
    }
};