class Solution {
public:
    int flipLights(int n, int presses) {
        if (presses >= 10)
            return 1 << min(n, 3);
        
        set<vector<int>> res;
        
        for (int a = 0; a <= presses; a++) {
            for (int b = 0; a + b <= presses; b++) {
                for (int c = 0; a + b + c <= presses; c++) {
                    int d = n - a - b - c;
                    
                    vector<int> bulbs(min(n, 4));
                    
                    if (a % 2)
                        for (int i = 0; i < bulbs.size(); i++)
                            bulbs[i] ^= 1;
                    
                    if (b % 2)
                        for (int i = 1; i < bulbs.size(); i += 2)
                            bulbs[i] ^= 1;
                    
                    if (c % 2)
                        for (int i = 0; i < bulbs.size(); i += 2)
                            bulbs[i] ^= 1;
                    
                    if (d % 2)
                        for (int i = 0; i < bulbs.size(); i += 3)
                            bulbs[i] ^= 1;
                    
                    res.insert(bulbs);
                }
            }
        }
        
        return res.size();
    }
};