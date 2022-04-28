class Solution {
    vector<int> gray(int n) {
        if (!n)
            return { 0, 1 };
        
        vector<int> a = gray(n - 1);
        
        vector<int> b = a;
        reverse(b.begin(), b.end());
        for (int &value : b)
            value += 1 << n;
        
        a.insert(a.end(), b.begin(), b.end());
        return a;
    }
    
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> a = gray(n - 1);
        rotate(a.begin(), find(a.begin(), a.end(), start), a.end());
        return a;
    }
};