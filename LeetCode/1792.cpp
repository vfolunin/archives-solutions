struct Fraction {
    int num, den;
    
    double bonus() const {
        return (double)(num + 1) / (den + 1) - (double)num / den;
    }
    
    bool operator < (const Fraction &that) const {
        return bonus() > that.bonus();
    }
};

class Solution {
public:
    double maxAverageRatio(vector<vector<int>> &classes, int extraStudents) {
        multiset<Fraction> fractions;
        for (vector<int> &c : classes)
            fractions.insert({ c[0], c[1] });
        
        for (int i = 0; i < extraStudents; i++) {
            auto [num, den] = *fractions.begin();
            fractions.erase(fractions.begin());
            fractions.insert({ num + 1, den + 1 });
        }
        
        double res = 0;
        for (auto &[num, den] : fractions)
            res += 1.0 * num / den;
        return res / classes.size();
    }
};