class Solution {
    bool rec(vector<int> &a, int i, vector<int> &used) {
        if (i == a.size())
            return 1;
        
        if (a[i])
            return rec(a, i + 1, used);
        
        for (int value = used.size() - 1; value; value--) {
            if (!used[value] && (value == 1 || i + value < a.size() && !a[i + value])) {
                a[i] = value;
                if (value > 1)
                    a[i + value] = value;
                used[value] = 1;
                
                if (rec(a, i + 1, used))
                    return 1;
                
                a[i] = 0;
                if (value > 1)
                    a[i + value] = 0;
                used[value] = 0;
            }
        }
        
        return 0;
    }
    
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> a(2 * n - 1), used(n + 1);
        rec(a, 0, used);
        return a;
    }
};