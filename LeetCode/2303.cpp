class Solution {
public:
    double calculateTax(vector<vector<int>> &brackets, int income) {
        double res = 0;
        for (int i = 0; i < brackets.size(); i++) {
            int amount = min(income, brackets[i][0] - (i ? brackets[i - 1][0] : 0));
            income -= amount;
            res += amount * brackets[i][1] / 100.0;
        }
        return res;
    }
};