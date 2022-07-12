class Solution {
public:
    vector<int> grayCode(int n) {
        if (n == 1)
            return { 0, 1 };
        
        vector<int> a = grayCode(n - 1), b = a;
        reverse(b.begin(), b.end());
        for (int &value : b)
            value += 1 << (n - 1);
        
        a.insert(a.end(), b.begin(), b.end());
        return a;
    }
};