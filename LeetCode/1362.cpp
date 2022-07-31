class Solution {
    pair<int, int> getClosest(int n) {
        int a = 1, b = n;
        for (int d = 2; d * d <= n; d++) {
            if (n % d == 0 && n / d - d < b - a) {
                a = d;
                b = n / d;
            }
        }
        return { a, b };
    }
    
public:
    vector<int> closestDivisors(int n) {
        auto [a1, b1] = getClosest(n + 1);
        auto [a2, b2] = getClosest(n + 2);
        
        if (b1 - a1 <= b2 - a2)
            return { a1, b1 };
        else
            return { a2, b2 };
    }
};