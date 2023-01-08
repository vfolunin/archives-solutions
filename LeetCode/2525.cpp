class Solution {
public:
    string categorizeBox(int a, int b, int c, int mass) {
        bool bulky = max({ a, b, c }) >= 1e4 || 1LL * a * b * c >= 1e9;
        bool heavy = mass >= 100;
        
        if (bulky && heavy)
            return "Both";
        else if (bulky)
            return "Bulky";
        else if (heavy)
            return "Heavy";
        else
            return "Neither";
    }
};