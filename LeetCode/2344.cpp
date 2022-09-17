class Solution {
public:
    int minOperations(vector<int> &a, vector<int> &b) {
        int d = 0;
        for (int value : b)
            d = gcd(d, value);
        
        sort(a.begin(), a.end());
        
        int i = 0;
        while (i < a.size() && d % a[i])
            i++;
        
        return i < a.size() ? i : -1;
    }
};