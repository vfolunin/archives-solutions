class Solution {
public:
    vector<int> prisonAfterNDays(vector<int> &a, int n) {
        map<vector<int>, int> seen;
        
        for (int i = 0; i < n; i++) {
            if (seen.count(a)) {
                int cycle = i - seen[a];
                int remaining = n - i - 1;
                remaining %= cycle;
                n = i + remaining + 1;
            }
            
            seen[a] = i;
            
            vector<int> nextA(8);
            for (int i = 1; i < 7; i++)
                nextA[i] = a[i - 1] && a[i + 1] || !a[i - 1] && !a[i + 1];
            a.swap(nextA);
        }
        
        return a;
    }
};