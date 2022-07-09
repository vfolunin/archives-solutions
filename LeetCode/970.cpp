class Solution {
public:
    vector<int> powerfulIntegers(int a, int b, int limit) {
        if (a > b)
            swap(a, b);
        
        unordered_set<int> res;
        
        if (b == 1) {
            if (2 <= limit)
                res.insert(2);
        } else if (a == 1) {
            for (int bx = 1; 1 + bx <= limit; bx *= b)
                res.insert(1 + bx);
        } else {
            for (int ax = 1; ax <= limit; ax *= a)
                for (int bx = 1; ax + bx <= limit; bx *= b)
                    res.insert(ax + bx);
        }
        
        return { res.begin(), res.end() };
    }
};